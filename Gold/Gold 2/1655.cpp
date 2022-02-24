#include <iostream>
#include <queue>

#define pqint(cmp) priority_queue<int, vector<int>, cmp>

using namespace std;

int l, r;

// debug function
template<typename T>
void print(pqint(T) q) {
    if (q.size() == 0) { cout << "[]"; return; }
    int sz = q.size();
    cout << "[";
    for (int i = 0; i < sz - 1; i++) {
        cout << q.top() << ", ";
        q.pop();
    } cout << q.top() << "]";
}

int main() {
    cin.tie(0); cin.sync_with_stdio(false);
    
    pqint(less<int>) lpq;    // left
    pqint(greater<int>) gpq; // right
    int n, tmp; cin >> n >> tmp; cout << tmp << "\n";
    lpq.push(tmp); l++; n -= 1;
    for (; n--; ) {
        cin >> tmp;
        
        int tp = lpq.top();
        
        if (tmp < tp) {
            if (l != r) { gpq.push(lpq.top()); lpq.pop(); r++; l--; }
            
            lpq.push(tmp); l++;
        } else if (tmp == tp) {
            if (l == r) { lpq.push(tmp); l++; }
            else { gpq.push(tmp); r++; }
        } else {
            gpq.push(tmp); r++;
            
            if (l != r) { lpq.push(gpq.top()); gpq.pop(); l++; r--; }
        }
        
        cout << lpq.top() << "\n";
    }
    
    return 0;
}