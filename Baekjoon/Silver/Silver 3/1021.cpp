#include <iostream>
#include <deque>

using namespace std;

int front(deque<int>& d, int target);
int back(deque<int>& d, int target);

int indexof(deque<int>& d, int target) {
    for (int i = 0; i < d.size(); i++) if (d.at(i) == target) return i;
}

int main() {
    int n, m, pos = 0, count = 0; cin >> n >> m;
    int target[m];
    deque<int> d;
    
    for (int i = 1; i <= n; i++) d.push_back(i);
    for (int i = 0; i <  m; i++) cin >> target[i];
    
    while (pos != m) {
        int f = d.front();
        if (f == target[pos]) { d.pop_front(); pos++; continue; }
        
        int (*fp)(deque<int>&, int) =
            indexof(d, target[pos]) > d.size() / 2 ? back : front;
        
        count += fp(d, target[pos]);
    }
    
    cout << count;
    
    return 0;
}

int front(deque<int>& d, int target) {
    int c = 0;
    while (d.front() != target) { d.push_back(d.front()); d.pop_front(); c++; }
    
    return c;
}

int back(deque<int>& d, int target) {
    int c = 0;
    while (d.back() != target) { d.push_front(d.back()); d.pop_back(); c++; }
    d.push_front(d.back()); d.pop_back(); c++;
    
    return c;
}