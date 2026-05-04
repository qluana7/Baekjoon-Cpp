#include <iostream>
#include <deque>

#define pii pair<short, short>

using namespace std;

int main() {
    int n; cin >> n;
    deque<pii> d;
    
    for (int i = 0 ; i < n; i++) {
        int x; cin >> x;
        d.push_back({ i + 1, x });
    }
    
    while (n --> 0) {
        auto [ind, x] = d.front(); d.pop_front();
        cout << ind << " ";
        
        for (int i = 0, len = abs(x) - (x > 0); i < len; i++) {
            if (x > 0) {
                d.push_back(d.front());
                d.pop_front();
            } else {
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }
    
    return 0;
}