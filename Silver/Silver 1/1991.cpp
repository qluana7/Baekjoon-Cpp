#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<int, int>> tree;

void preo(int nd) {
    if (nd == '.') return;
    
    cout << (char)nd;
    
    preo(tree[nd].first);
    preo(tree[nd].second);
}

void ino(int nd) {
    if (nd == '.') return;
    
    ino(tree[nd].first);
    
    cout << (char)nd;
    
    ino(tree[nd].second);
}

void posto(int nd) {
    if (nd == '.') return;
    
    posto(tree[nd].first);
    posto(tree[nd].second);
    
    cout << (char)nd;
}

int main() {
    int n; cin >> n;
    
    for (;n--;) {
        char p, a, b; cin >> p >> a >> b;
        tree[p] = {a, b};
    }
    
    preo('A');  cout << "\n";
    ino('A');   cout << "\n";
    posto('A'); cout << "\n";
    
    return 0;
}