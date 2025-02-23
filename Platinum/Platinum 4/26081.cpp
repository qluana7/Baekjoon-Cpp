/*
# How to get Parent's Point.

# Parent's Anchor Point
DEFINE PA1, PA2
# Parent's Screen Point
DEFINE SP1, SP2
# Parent's Size
DEFINE PS1, PS2
# Child's Parent Origin Point
DEFINE PO1, PO2

IF   (PA1, PA2 = { 0, 0 }) THEN
    PO1, PO2 = { 0, 0 } -> ret SP1,       SP2
    PO1, PO2 = { 0, 1 } -> ret SP1,       SP2 + PS2
    PO1, PO2 = { 1, 0 } -> ret SP1 + PS1, SP2
    PO1, PO2 = { 1, 1 } -> ret SP1 + PS1, SP2 + PS2
ELIF (PA1, PA2 = { 0, 1 }) THEN
    PO1, PO2 = { 0, 0 } -> ret SP1,       SP2 - PS2
    PO1, PO2 = { 0, 1 } -> ret SP1,       SP2
    PO1, PO2 = { 1, 0 } -> ret SP1 + PS1, SP2 - PS2
    PO1, PO2 = { 1, 1 } -> ret SP1 + PS1, SP2
ELIF (PA1, PA2 = { 1, 0 }) THEN
    PO1, PO2 = { 0, 0 } -> ret SP1 - PS1, SP2
    PO1, PO2 = { 0, 1 } -> ret SP1 - PS1, SP2 + PS2
    PO1, PO2 = { 1, 0 } -> ret SP1,       SP2
    PO1, PO2 = { 1, 1 } -> ret SP1,       SP2 + PS2
ELIF (PA1, PA2 = { 1, 1 }) THEN
    PO1, PO2 = { 0, 0 } -> ret SP1 - PS1, SP2 - PS2
    PO1, PO2 = { 0, 1 } -> ret SP1 - PS1, SP2
    PO1, PO2 = { 1, 0 } -> ret SP1,       SP2 - PS2
    PO1, PO2 = { 1, 1 } -> ret SP1,       SP2
END

# '*' is negative case of PS1
##
   PA1 PA2 PO1 PO2 | PA1 ^ PO1 | PA2 ^ PO2 | TODO
   0   0   0   0   |     0     |     0     | Normal
   0   0   0   1   |     0     |     1     | + PS2
   0   0   1   0   |     1     |     0     | + PS1
   0   0   1   1   |     1     |     1     | + PS1 + PS2
   0   1   0   0   |     0     |     1     | - PS2
   0   1   0   1   |     0     |     0     | Normal
   0   1   1   0   |     1     |     1     | + PS1 - PS2
   0   1   1   1   |     1     |     0     | + PS1
 * 1   0   0   0   |     1     |     0     | - PS1
 * 1   0   0   1   |     1     |     1     | - PS1 + PS2
   1   0   1   0   |     0     |     0     | Normal
   1   0   1   1   |     0     |     1     | + PS2
 * 1   1   0   0   |     1     |     1     | - PS1 - PS2
 * 1   1   0   1   |     1     |     0     | - PS1
   1   1   1   0   |     0     |     1     | - PS2
   1   1   1   1   |     0     |     0     | Normal
##

# Parent Anchor, Parent Origin, Screen Point, Parent Size
REQUIRES( PA, PO, SP, PS )
# Parent's Point ( = Result)
DEFINE PP1, PP2

PP1 <- SP1 +
        IF(PA1 ^ PO1) THEN
            PS1 * (
                IF(PA1) THEN -1
                ELSE 1
            )
        ELSE 0
PP2 <- # Same as PP1.


# Get Screen Position

# Parent's Point
DEFINE PP1, PP2
# Child's Size
DEFINE S1, S2

# Because Screen Position is based on Child's Anchor Point.
#     So, don't need to consider other things.
SP1 = PP1 + S1
SP2 = PP2 + S2


# Get Absolute Position
##
* Absolute Position?

Absolute Position means the position of the object in the screen
    without considering the anchor point.
##

# Screen Position
DEFINE SP1, SP2
# Child's Anchor Point
DEFINE AP1, AP2
# Child's Size
DEFINE S1, S2

AB1 = SP1 - AP1 * S1
AB2 = SP2 - AP2 * S2

*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>

/* Primitive Type Declaration. */
#include <cstdint>

#define i8  int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t
#define u8  uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
/* -------------------------- */

#define INF 2147483647 

using namespace std;

struct actor;

static actor* window;
static unordered_map<string, actor*> actor_map;

template <typename T1, typename T2>
struct vector2 {

    T1 m1; T2 m2;

    friend ostream& operator<<(ostream& __os, vector2 v)
    { return __os << v.m1 << " " << v.m2; }
};

struct actor {
public:
    actor() = default;
    actor(const actor&) = default;
    actor(actor&&) = default;

private:
    actor* parent = nullptr;
    list<actor*> children;

    vector2<i32, i32> pos, size;
    vector2<bool, bool> porg, apt;
    i32 color = 1;

public:
    inline       vector2<i32, i32>    get_screen_pos()    const;
    inline       vector2<i32, i32>    get_absolute_pos()  const;
    inline const vector2<i32, i32>&   get_pos()           const { return this->pos;      }
    inline const vector2<i32, i32>&   get_size()          const { return this->size;     }
    inline const vector2<bool, bool>& get_parent_origin() const { return this->porg;     }
    inline const vector2<bool, bool>& get_anchor_point()  const { return this->apt;      }
    inline       i32                  get_color()         const { return this->color;    }
    inline       actor*               get_parent()        const { return this->parent;   }
    inline const list<actor*>&        get_children()      const { return this->children; }
    
    void set_pos(i32 __x, i32 __y) { pos = { __x, __y }; }
    void set_size(i32 __w, i32 __h) { size = { __w, __h }; }
    void set_parent_origin(bool __x, bool __y) { porg = { __x, __y }; }
    void set_anchor_point(bool __x, bool __y) { apt = { __x, __y }; }
    void set_color(i32 __c) { this->color = __c; }

    void add(actor* __child) { this->children.push_back(__child); __child->parent = this; }
    void remove(actor* __child) { this->children.remove(__child); __child->parent = nullptr; }
};

inline vector2<i32, i32> actor::get_screen_pos() const {
    if (this->parent == nullptr) {
        if (this == window) return { 0, 0 };
        else return { INF, INF };
    }
    
    auto [pa1, pa2] = this->parent->apt;
    auto [po1, po2] = this->porg;
    auto [sp1, sp2] = this->parent->get_screen_pos();
    auto [ps1, ps2] = this->parent->size;

    if (sp1 == INF) return { INF, INF };

    i32
        pp1 = sp1 + ((pa1 ^ po1) ? ps1 * (pa1 ? -1 : 1) : 0),
        pp2 = sp2 + ((pa2 ^ po2) ? ps2 * (pa2 ? -1 : 1) : 0);
    
    auto [p1, p2] = this->pos;

    return { pp1 + p1, pp2 + p2 };
}

inline vector2<i32, i32> actor::get_absolute_pos() const {
    auto [sp1, sp2] = this->get_screen_pos();
    auto [ap1, ap2] = this->get_anchor_point();
    auto [s1, s2] = this->size;

    return { sp1 - ap1 * s1, sp2 - ap2 * s2 };
}

void __new(const string& name) {
    actor_map[name] = new actor();
}

void __unparent(const string& name);

void __add(const string& a1, const string& a2) {
    __unparent(a2);
    actor_map[a1]->add(actor_map[a2]);
}

void __remove(const string& a1, const string& a2) {
    actor *_a1 = actor_map[a1], *_a2 = actor_map[a2];

    if (_a2->get_parent() != _a1) return;

    _a1->remove(_a2);
}

void __unparent(const string& name) {
    actor *act = actor_map[name], *par = act->get_parent();

    if (par == nullptr) return;

    par->remove(act);
}

void __set(const string& name, const string& prop, i32 p1, i32 p2 = INF) {
    actor* act = actor_map[name];

    switch (prop.size()) {
        case 4:  act->set_size         (p1, p2); break;
        case 5:  act->set_color        (p1    ); break;
        case 8:  act->set_pos          (p1, p2); break;
        case 12: act->set_anchor_point (p1, p2); break;
        case 13: act->set_parent_origin(p1, p2); break;
    }
}

void __get(const string& name, const string& prop) {
    actor* act = actor_map[name];

    switch (prop.size()) {
        case 4:  cout << act->get_size         (); break;
        case 5:  cout << act->get_color        (); break;
        case 8:  cout << act->get_pos          (); break;
        case 12: cout << act->get_anchor_point (); break;
        case 13: cout << act->get_parent_origin(); break; 
        case 15: {
            auto [p1, p2] = act->get_screen_pos();
            if (p1 == INF) p1 = 0, p2 = 0;
            cout << p1 << " " << p2;
            break;
        }
    }

    cout << "\n";
}

void _new() {
    string name; cin >> name;
    __new(name);
}

void _add() {
    string a1, a2; cin >> a1 >> a2;
    __add(a1, a2);
}

void _remove() {
    string a1, a2; cin >> a1 >> a2;
    __remove(a1, a2);
}

void _unparent() {
    string name; cin >> name;
    __unparent(name);
}

void _set() {
    string name, prop; i32 p1, p2;

    cin >> name >> prop >> p1;

    switch (prop.size()) {
        case 4: case 8: case 12: case 13:
            cin >> p2;
        default: break;
    }

    __set(name, prop, p1, p2);
}

void _get() {
    string name, prop; cin >> name >> prop;
    __get(name, prop);
}

void _fill(vector<vector<i32>>& scr, actor* root) {
    auto [sp1, sp2] = root->get_absolute_pos();
    auto [s1, s2] = root->get_size();
    i32 c = root->get_color();
    auto [w, h] = window->get_size();

    for (i32 i = 0; i < s1; i++) {
        i32 p1 = sp1 + i;

        if (p1 < 0 || w <= p1) continue;

        for (i32 j = 0; j < s2; j++) {
            i32 p2 = sp2 + j;
            
            if (p2 < 0 || h <= p2) continue;
        
            
            scr[p2][p1] = c;
        }
    }

    for (auto n : root->get_children())
        _fill(scr, n);
}

inline constexpr u8 __hash (string_view str) {
    constexpr u8 asso_values[] = {
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17,  2, 17, 17, 17, 17,
        17,  5, 17, 17, 17, 17, 17, 17,  0, 17,
        17, 17,  0,  0, 17,  0, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17
    };

    return str.size() + asso_values[static_cast<u8>(str[0])];
}

void(*jtable[])() = {
    nullptr, nullptr, nullptr,
    _new, nullptr,
    _add,
    _remove, nullptr,
    _unparent, nullptr, nullptr,
    _set, nullptr, nullptr, nullptr, nullptr,
    _get,
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    i32 w, h; cin >> w >> h;
    window = new actor(); {
        window->set_size(w, h);
        window->set_color(0);
    }
    actor_map["Window"] = window;

    i32 n; cin >> n;
    while (n --> 0) {
        string s; cin >> s;
        
        jtable[__hash(s)]();
    }

    vector<vector<i32>> scr(h, vector<i32>(w, 0));
    _fill(scr, window);

    for (auto& vx : scr) {
        for (auto x : vx) cout << x;
        cout << "\n";
    }
}