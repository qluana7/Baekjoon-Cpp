#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int st = 0, en; cin >> en;
    vector<int> v;
    
    for (int i = 0; i < en; i++) {
        int x; cin >> x;
        v.push_back(x);
    } sort(v.begin(), v.end());
    
    int sum; cin >> sum;
    int count = 0; en--;
    
    while (st != en) {
        if (v[st] + v[en] == sum) count++;
        if (v[st] + v[en] > sum) en--;
        else st++;
    }
    
    cout << count;
    
    return 0;
}