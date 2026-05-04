#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map<int, int> res;

int rec(int a, int b, int c);

inline int get(int a, int b, int c)
{ return a * 10000 + b * 100 + c; }

int cache(int a, int b, int c) {
    int g = get(a, b, c);
    if (res.count(g) != 0) return res[g];
    int x = rec(a, b, c);
    return res[g] = x;
}

int rec(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return cache(20, 20, 20);
    if (a < b && b < c) return cache(a, b, c - 1) + cache(a, b - 1, c - 1) - cache(a, b - 1, c);
    else return cache(a - 1, b, c) + cache(a - 1, b - 1, c) + cache(a - 1, b, c - 1) - cache(a - 1, b - 1, c - 1);
}

int main() {
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, rec(a, b, c));
    }
    
    return 0;
}