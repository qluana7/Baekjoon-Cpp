#include <iostream>
#include <cmath>

using namespace std;

struct pos { double x, y; };

int main() {
    double w = 0;
    int n; cin >> n;
    pos p; cin >> p.x >> p.y;
    pos prev; cin >> prev.x >> prev.y;
    prev.x -= p.x; prev.y -= p.y;
    
    for (int i = 2; i < n; i++) {
        pos m; cin >> m.x >> m.y;
        m.x -= p.x; m.y -= p.y;
        
        w += (prev.x * m.y - prev.y * m.x);
        
        prev = m;
    }
    
    cout.precision(1);
    cout << fixed << round(fabs(w) * 5) / 10;
    
    return 0;
}