#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define gt(x, n) ((x) == (n) ? 1 : 0)
#define gtp(n) {gt(n, -1), gt(n, 0), gt(n, 1)}

using namespace std;

vector<vector<int>> vec;

tuple<int, int, int> get(int x, int y, int s) {
    int sz = vec.size();
    int prev = vec[x][y];
    if (s == 1) return gtp(prev);
    
    int a = 0, b = 0, c = 0;
    
    int z = 0;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (vec[x + i][y + j] == prev) z++;
        }
    }
    if (s * s == z) return gtp(prev);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int tmp = s / 3;
            auto [ga, gb, gc] = get(x + tmp * i, y + tmp * j, tmp);
            a += ga; b += gb; c += gc;
        }
    }
    
    return {a, b, c};
}

int main() {
    int n; cin >> n;
    int t = -2;
    
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (t != -2 && t != 2 && t != x) t = 2;
            else t = x;
            v.push_back(x);
        }
        vec.push_back(v);
    }
    
    auto [a, b, c] = get(0, 0, n);
    
    cout << a << "\n" << b << "\n" << c;
    
    return 0;
}