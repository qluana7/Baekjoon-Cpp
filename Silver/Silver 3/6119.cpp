#include <iostream>
#include <deque>

using namespace std;

int main() {
    int rp, n = 1; cin >> rp;
    deque<int> d;
    
    for (;rp--;) {
        char a, b; cin >> a >> b;
        
        if (a == 'D') {
            int c; cin >> c;
            
            for (;c--;) {
                if (b == 'L') d.pop_front();
                else d.pop_back();
            }
        } else {
            if (b == 'L') d.push_front(n++);
            else d.push_back(n++);
        }
    }
    
    for (auto x : d) cout << x << "\n";
    
    return 0;
}