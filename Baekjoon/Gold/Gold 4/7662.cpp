#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main() {
    cin.tie(0); cin.sync_with_stdio(false);
    int re; cin >> re;
    
    for (; re--;) {
        multiset<int> mset;
        int n; cin >> n;
        
        for (; n--;) {
            char cmd; int v; cin >> cmd >> v;
            
            if (cmd == 'I') {
                mset.insert(v);
            } else {
                if (v == 1) { if (!mset.empty()) mset.erase(--mset.end()); }
                else { if(!mset.empty()) mset.erase(mset.begin()); }
            }
        }
        
        if (mset.size() == 0) cout << "EMPTY";
        else {
            cout << (*--mset.end()) << " " << (*mset.begin());
        }
        
        cout << "\n";
    }
    
    return 0;
}