#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <optional>

#include <cstdint>

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using f32 = float;
using f64 = double;

using namespace std;

inline void concat(string& orig, const string& str, char delim) {
    if (orig.empty()) orig = str;
    else orig = orig + delim + str;
}

struct Piece {
    enum class Poly : i32 {
        None, Circle, Rectangle, Windmill, Star
    };

    enum class Color : i32 {
        None, Red, Green, Blue, Yellow, Purple, Cyan, Uncolored, White
    };

    static constexpr char p2ch(Poly p)
    { return "-CRWS"[static_cast<i32>(p)]; }

    static constexpr char c2ch(Color c)
    { return "-rgbypcuw"[static_cast<i32>(c)]; }

    static constexpr Poly ch2p(char c);
    static constexpr Color ch2c(char c);

    Piece() : p(Poly::None), c(Color::None) { }
    Piece(const Piece&) = default;
    Piece(char _p, char _c) : p(ch2p(_p)), c(ch2c(_c)) { }

    Poly p; Color c;

    inline string p2s() const
    { return string{} + p2ch(p) + c2ch(c); }

    constexpr explicit operator bool() const
    { return p != Poly::None; }
};

constexpr Piece::Poly Piece::ch2p(char c) {
    switch (c) {
        case '-': return Poly::None;
        case 'C': return Poly::Circle;
        case 'R': return Poly::Rectangle;
        case 'W': return Poly::Windmill;
        case 'S': return Poly::Star;
    }
}

constexpr Piece::Color Piece::ch2c(char c) {
    switch (c) {
        case '-': return Color::None;
        case 'r': return Color::Red;
        case 'g': return Color::Green;
        case 'b': return Color::Blue;
        case 'y': return Color::Yellow;
        case 'p': return Color::Purple;
        case 'c': return Color::Cyan;
        case 'u': return Color::Uncolored;
        case 'w': return Color::White;
    }
}

struct Shape {
    enum class RotateValue : i32 {
        r90, r180, r270
    };

    typedef array<Piece, 4> _Shape;

    Shape() = default;
    Shape(const Shape&) = default;
    Shape(const string& str);

    array<_Shape, 4> shapes;
    i32 level = 0;
    
    void rotate(RotateValue rv);

    string str() const {
        string s;

        for (i32 i = 0; i < level; i++) {
            string t;
            for (i32 j = 0; j < 4; j++)
                t += shapes[i][j].p2s();
            
            concat(s, t, ':');
        }

        return s;
    }
};

Shape::Shape(const string& str) {
    stringstream ss(str);

    string s; i32 lv = 0;
    for (; getline(ss, s, ':'); lv++) {
        for (i32 i = 0; i < 4; i++)
            shapes[lv][i] = Piece(s[i * 2], s[i * 2 + 1]);
    }

    level = lv;
}

void Shape::rotate(Shape::RotateValue rv) {
    for (i32 i = 0; i < level; i++) {
        _Shape sp = shapes[i];

        for (i32 j = 0, k = static_cast<i32>(rv) + 1; j < 4; j++, k++)
            shapes[i][k % 4] = sp[j];
    }
}

array<optional<Shape>, 101> reg;

void cut(i32 i, i32 o1, i32 o2) {
    if (!reg[i].has_value()) {
        reg[o1].reset(); reg[o2].reset();
        return;
    }

    const Shape& sp = *reg[i];
    Shape lsp, rsp;
    i32 l = 0, r = 0;

    for (i32 k = 0; k < sp.level; k++) {
        Shape::_Shape lp, rp;

        lp[0] = sp.shapes[k][0];
        lp[1] = sp.shapes[k][1];

        if ((bool)lp[0] || (bool)lp[1])
            lsp.shapes[l++] = lp;

        rp[2] = sp.shapes[k][2];
        rp[3] = sp.shapes[k][3];

        if ((bool)rp[2] || (bool)rp[3])
            rsp.shapes[r++] = rp;
    }

    lsp.level = l; rsp.level = r;

    if (r != 0) reg[o1] = rsp;
    else reg[o1].reset();

    if (l != 0) reg[o2] = lsp;
    else reg[o2].reset();
}

void rotate(i32 i, i32 o, i32 v) {
    if (!reg[i].has_value()) {
        reg[o].reset();
        return;
    }

    reg[o] = reg[i];
    reg[o]->rotate(static_cast<Shape::RotateValue>(v - 1));
}

void comb(i32 i1, i32 i2, i32 o) {
    if (!reg[i1].has_value() || !reg[i2].has_value()) {
        reg[o].reset();
        return;
    }

    const Shape &p = *reg[i1], &q = *reg[i2];

    i32 b1 = 0, b2 = 0;

    for (i32 i = 0; i < p.level; i++) {
        i32 k = 0;
        
        for (i32 j = 0; j < 4; j++)
            k <<= 1, k |= (bool)p.shapes[i][j];
        
        b1 |= (k << i * 4);
    }

    for (i32 i = 0; i < q.level; i++) {
        i32 k = 0;
        
        for (i32 j = 0; j < 4; j++)
            k <<= 1, k |= (bool)q.shapes[i][j];
        
        b2 |= (k << i * 4);
    }
    
    b2 <<= 12;

    i32 k = 4;
    for (; k > 0 && !(b1 & b2); k--) b2 >>= 4;
    
    Shape r = p;

    for (i32 i = k, j = 0; i < 4 && j < q.level; i++, j++) {
        for (i32 x = 0; x < 4; x++)
            if (!((bool)r.shapes[i][x])) r.shapes[i][x] = q.shapes[j][x];
    }

    r.level = min(max(p.level, k + q.level), 4);
    reg[o] = r;
}

void color(i32 i, i32 o, i32 v) {
    if (!reg[i].has_value()) {
        reg[o].reset();
        return;
    }

    Shape sp = *reg[i];

    for (i32 k = 0; k < sp.level; k++) {
        for (auto& s : sp.shapes[k]) {
            if (s.p != Piece::Poly::None)
                s.c = Piece::ch2c(v);
        }
    }

    reg[o] = sp;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    i32 n, m; cin >> n >> m;

    for (i32 i = 1; i <= n; i++) {
        string s; cin >> s;
        reg[i] = Shape(s);
    }
    
    while (m --> 0) {
        i32 k, a, b, c; char _;
        cin >> k >> a >> b;
        if (k == 4) cin >> _, c = _;
        else cin >> c;

        ((void (*[])(i32, i32, i32)) { cut, rotate, comb, color })[k - 1](a, b, c);
    }

    cout << (reg[100].has_value() ? reg[100]->str() : "None");
}