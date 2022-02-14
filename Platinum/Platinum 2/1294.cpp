#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct obj {
    string str;
    size_t size;
    int pos;
};

bool cmp(obj& d1, obj& d2) {
    if (d1.pos == d1.size) return false;
    else if (d2.pos == d2.size) return true;
    else {
        int p1 = d1.pos, p2 = d2.pos;
        while (p1 < d1.size && p2 < d2.size && d1.str[p1] == d2.str[p2]) {
            p1++; p2++;
        }
        
        if (p1 == d1.size) return false;
        else if (p2 == d2.size) return true;
        else return d1.str[p1] < d2.str[p2];
    }
}

int main() {
    int n; cin >> n;
    vector<obj> v;
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v.push_back({s, s.length(), 0});
    }
    
    while (!v.empty()) {
        sort(v.begin(), v.end(), cmp);
        
        cout << v[0].str[v[0].pos];
        v[0].pos++;
        
        int sz = v.size();
        while (sz-- && v[sz].pos == v[sz].size) v.pop_back();
    }
    
    return 0;
}