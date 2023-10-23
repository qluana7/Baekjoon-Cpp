#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    deque<int> d;
    
    while (n --> 0) {
        int c, x; cin >> c;
        
        switch (c) {
        case 1:
            cin >> x;
            d.push_front(x);
            break;
        case 2:
            cin >> x;
            d.push_back(x);
            break;
        case 3:
            if (d.empty()) x = -1;
            else {
                x = d.front(); d.pop_front();
            }
            cout << x << "\n";
            break;
        case 4:
            if (d.empty()) x = -1;
            else {
                x = d.back(); d.pop_back();
            }
            cout << x << "\n";
            break;
        case 5:
            cout << d.size() << "\n";
            break;
        case 6:
            cout << (d.empty() ? 1 : 0) << "\n";
            break;
        case 7:
            cout << (d.empty() ? -1 : d.front()) << "\n";
            break;
        case 8:
            cout << (d.empty() ? -1 : d.back()) << "\n";
            break;
        }
    }
     
    return 0;
}