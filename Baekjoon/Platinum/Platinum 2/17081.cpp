// ONLINE_JUDGE = remove debug code.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

#define byte_t unsigned char

struct pos_t {
    int x, y;
    
    bool operator== (pos_t p) { return this->x == p.x && this->y == p.y; }
};
struct hp_t {
    short cur, max;
    
    void update(int n) { cur = min(static_cast<short>(cur + n), max); }
};

enum orn_t : byte_t
{ HR, RE, CO, EX, DX, HU, CU };

enum item_t : byte_t
{ WEAPON, ARMOR, ORNAMENT };

struct item { byte_t buf; };

struct weapon   : item { };
struct armor    : item { };
struct ornament : item { };

struct tile {
protected:
    tile(int x, int y) : p({x, y}) { };
public:
    pos_t p;
    
    inline virtual char getc() = 0;
    virtual void active() = 0;
};

struct player {
    pos_t pos;
    
    hp_t hp;
    short atk, def;
    int lv, exp;
    weapon wp; armor am;
    unordered_set<orn_t> om;
    
    short get_atk() { return (this->atk + this->wp.buf); }
    short get_def() { return (this->def + this->am.buf); }
    int get_mult() { return this->om.count(orn_t::CO) ? this->om.count(orn_t::DX) ? 3 : 2 : 1; }
    void update_exp(int exp);
};

void player::update_exp(int exp) {
    this->exp += exp * (this->om.count(orn_t::EX) ? 12 : 10) / 10;
    
    if (this->exp >= this->lv * 5) {
        #ifndef ONLINE_JUDGE
        cout << "Level up!\n";
        #endif
        this->exp = 0; this->lv++;
        this->hp.max += 5;
        this->hp.cur = this->hp.max;
        this->atk += 2; this->def += 2;
    }
}

player _player;
vector<vector<tile*>> map;
int sx, sy, turn;
/*
 * 1 << 0 = WIN
 * 1 << 1 = DEAD
 * 
 * 1 << 2 ~ 8  = pos_x
 * 1 << 9 ~ 15 = pos_y
 */
int flag;

struct blank : tile {
    blank(int x, int y) : tile(x, y) { };
    
    char getc() override { return '.'; };
    void active() override;
};

void blank::active() {
    _player.pos = p;
}

struct wall : tile {
    wall(int x, int y) : tile(x, y) { };
    
    char getc() override { return '#'; };
    void active() override;
};

void wall::active() { }

struct ibox : tile {
    ibox(int x, int y) : tile (x, y) { }
    ibox(int x, int y, item_t itmt, item* it) : tile(x, y), itm(it) { }
    
    char getc() override { return 'B'; };
    void active() override;
    
    item* itm;
    item_t itmt;
};

void ibox::active() {
    switch (itmt)
    {
    case item_t::WEAPON:   _player.wp.buf = itm->buf; break;
    case item_t::ARMOR:    _player.am.buf = itm->buf; break;
    case item_t::ORNAMENT:
        if (!_player.om.count((orn_t)itm->buf) && _player.om.size() < 4)
            _player.om.insert((orn_t)((ornament*)itm)->buf);
        break;
    }
    
    pos_t tp = p;
    
    free(map[p.x][p.y]);
    map[tp.x][tp.y] = new blank(tp.x, tp.y);
    _player.pos = tp;
}

struct spike : tile {
    spike(int x, int y) : tile(x, y) { };
    
    char getc() override { return '^'; };
    void active() override;
};

void spike::active() {
    _player.hp.cur -= (_player.om.count(orn_t::DX) ? 1 : 5);
    _player.pos = p;
    
    #ifndef ONLINE_JUDGE
    cout << "Spike : " << _player.hp.cur << "\n";
    #endif
    
    if (_player.hp.cur <= 0) {
        flag |= 1 << 1;
        flag |= this->p.x << 2;
        flag |= this->p.y << 9;
    }
}

struct monster : tile {
    struct entity {
        string name;
        hp_t hp;
        short atk, def, exp;
    };
    
    monster(int x, int y, entity ett, bool boss = false) : tile(x, y), info(ett), is_boss(boss) { };
    
    char getc() override { return this->is_boss ? 'M' : '&'; };
    void active() override;
    
    entity info;
    bool is_boss;
};

void monster::active() {
    #ifndef ONLINE_JUDGE
    cout << "Monster Start\n";
    cout << "Monster Info : { Hp : " << this->info.hp.max << ", Atk : " << this->info.atk << ", Def : " << this->info.def << ", Exp : " << this->info.exp << " }\n";
    #endif
    bool fat = true;
    while (true) {
        this->info.hp.cur -= max(1, _player.get_atk() * (fat ? _player.get_mult() : 1) - this->info.def);
        #ifndef ONLINE_JUDGE
        cout << "Player Attack -[ " << max(1, _player.get_atk() - this->info.def) << " ]-> " << this->info.hp.cur << "\n";
        #endif
        if (this->info.hp.cur <= 0) break;
        
        if (fat) {
            fat = false;
            if (is_boss && _player.om.count(orn_t::HU)) {
                _player.hp.cur = _player.hp.max;
                continue;
            } else _player.hp.cur -= max(1, this->info.atk - _player.get_def());
        }
        else _player.hp.cur -= max(1, this->info.atk - _player.get_def());
        #ifndef ONLINE_JUDGE
        cout << "Monster Attack -[ " << max(1, this->info.atk - _player.get_def()) << " ]-> " << _player.hp.cur << "\n";
        #endif
        if (_player.hp.cur <= 0) break;
    }
    
    #ifndef ONLINE_JUDGE
    cout << "Monster : " << info.hp.cur << ", Player : " << _player.hp.cur << "\n";
    #endif
    
    if (this->info.hp.cur <= 0) {
        if (this->is_boss) flag |= 1 << 0;
        
        pos_t p = this->p;
        free(map[this->p.x][this->p.y]);
        map[p.x][p.y] = new blank(p.x, p.y);
        
        if (_player.om.count(orn_t::HR)) _player.hp.update(3);
        _player.update_exp(this->info.exp);
        _player.pos = p;
    } else {
        if (_player.om.count(orn_t::RE)) this->info.hp.cur = this->info.hp.max;
        flag |= 1 << 1;
        flag |= this->p.x << 2;
        flag |= this->p.y << 9;
    }
    
    #ifndef ONLINE_JUDGE
    cout << "Monster End\n";
    #endif
}

orn_t get_orn(string str) {
    if (str == "HR") return orn_t::HR;
    if (str == "RE") return orn_t::RE;
    if (str == "CO") return orn_t::CO;
    if (str == "EX") return orn_t::EX;
    if (str == "DX") return orn_t::DX;
    if (str == "HU") return orn_t::HU;
    if (str == "CU") return orn_t::CU;
    return (orn_t)255;
}

void move(int dx, int dy) {
    pos_t p = _player.pos;
    p.x += dx; p.y += dy;
    
    if (p.x < 0 || p.x >= sx) p.x -= dx;
    if (p.y < 0 || p.y >= sy) p.y -= dy;
    
    map[p.x][p.y]->active();
    if (map[p.x][p.y]->getc() == '#') map[p.x - dx][p.y - dy]->active();
}

void result() {
    bool sp = flag & 1 << 1;
    
    for (const auto& vec : map) {
        for (const auto& t : vec) {
            if (!sp && t->p == _player.pos) cout << '@';
            else cout << t->getc();
        }
        cout << "\n";
    }
    
    cout << "Passed Turns : " << turn << "\n";
    cout << "LV : " << _player.lv << "\n";
    cout << "HP : " << max(_player.hp.cur, (short)0) << "/" << _player.hp.max << "\n";
    cout << "ATT : " << _player.atk << "+" << (int)_player.wp.buf << "\n";
    cout << "DEF : " << _player.def << "+" << (int)_player.am.buf << "\n";
    cout << "EXP : " << _player.exp << "/" << _player.lv * 5 << "\n";
    
    if (flag & 1) cout << "YOU WIN!";
    else if (flag & 2) {
        auto t = map[flag >> 2 & 127][flag >> 9 & 127];
        cout << "YOU HAVE BEEN KILLED BY " << (t->getc() == '^' ? "SPIKE TRAP" : ((monster*)t)->info.name) << "..";
    } else if ((flag & 3) == 0) cout << "Press any key to continue.";
    
    for (const auto& vec : map)
        for (auto& n : vec)
            free(n);
}

#ifndef ONLINE_JUDGE
#include <iterator>
#endif

int main() {
    _player = player {
        {-1, -1},
        {20, 20}, 2, 2,
        1, 0,
        { 0 }, { 0 }, unordered_set<orn_t>(4)
    };
    
    int cm = 1, cb = 0;
    pos_t spos;
    
    cin >> sx >> sy;
    
    for (int i = 0; i < sx; i++) {
        getchar();
        vector<tile*> vec;
        for (int j = 0; j < sy; j++) {
            int ch = getchar();
            
            switch (ch)
            {
            case '.': vec.push_back(new blank(i, j));              break;
            case '#': vec.push_back(new wall(i ,j));               break;
            case '&': vec.push_back(new monster(i, j, {})); cm++;  break;
            case 'B': vec.push_back(new ibox(i, j));        cb++;  break;
            case '^': vec.push_back(new spike(i, j));              break;
            case 'M': vec.push_back(new monster(i, j, {}, true));  break;
            case '@':
                vec.push_back(new blank(i, j));
                _player.pos = { i, j };
                spos = _player.pos;
                break;
            }
        }
        map.push_back(vec);
    }
        
    string mvstr; cin >> mvstr;
    
    for (int i = 0; i < cm; i++) {
        int x, y; string name;
        short w, a, h, e;
        cin >> x >> y >> name
            >> w >> a >> h >> e;
        
        ((monster*)map[x - 1][y - 1])->info = {name, {h, h}, w, a, e};
    }
    
    for (int i = 0; i < cb; i++) {
        item* it; item_t tp;
        int x, y; char ot;
        
        cin >> x >> y >> ot;
        
        if (ot == 'O') {
            string otstr; cin >> otstr;
            
            it = new ornament {get_orn(otstr)};
            tp = item_t::ORNAMENT;
        } else {
            int n; cin >> n;
            if (ot == 'W') { it = new weapon {static_cast<byte_t>(n)}; tp = item_t::WEAPON; }
            else           { it = new armor  {static_cast<byte_t>(n)}; tp = item_t::ARMOR;  }
        }
        
        ((ibox*)map[x - 1][y - 1])->itmt = tp;
        ((ibox*)map[x - 1][y - 1])->itm = it;
    }
    
    for (char c : mvstr) {
        #ifndef ONLINE_JUDGE
        cout << "Move : " << c << "\n";
        
        cout << "LV : " << _player.lv << ", ";
        cout << "HP : " << max(_player.hp.cur, (short)0) << "/" << _player.hp.max << ", ";
        cout << "ATT : " << _player.atk << "+" << (int)_player.wp.buf << ", ";
        cout << "DEF : " << _player.def << "+" << (int)_player.am.buf << ", ";
        cout << "EXP : " << _player.exp << "/" << _player.lv * 5 << "\n";
        #endif
        
        switch (c)
        {
        case 'U': move(-1, 0); break;
        case 'D': move(1,  0); break;
        case 'L': move(0, -1); break;
        case 'R': move(0,  1); break;
        }
        
        turn++;
        
        if (flag != 0) {
            if ((flag & 1 << 1) && _player.om.count(orn_t::RE)) {
                #ifndef ONLINE_JUDGE
                cout << "Relive!\n";
                #endif
                _player.hp.cur = _player.hp.max;
                _player.pos = spos;
                _player.om.erase(orn_t::RE);
                flag = 0;
            }
            else { result(); return 0; }
        }
        
        #ifndef ONLINE_JUDGE
        cout << "Ornt : ";
        copy(_player.om.begin(), _player.om.end(), ostream_iterator<int>(cout, " "));
        cout << "\nPos : " << _player.pos.x << ", " << _player.pos.y << "\n";
        #endif
    }
    
    result();
    
    return 0;
}