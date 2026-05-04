#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int m;

string cpypad(long x, int n) {
    string z = to_string(x), p = z;
    
    for (int i = n; i--;) p += z;
    
    return p.substr(0, m);
}

bool compare(long& a, long& b) {
    string x = cpypad(a, m / ((int)log10(a) + 1) + 1);
    string y = cpypad(b, m / ((int)log10(b) + 1) + 1);
    
    return strcmp(x.data(), y.data()) > 0;
}

int main() {
    int a; long mx = 0, sum = 0; cin >> a;
    vector<long> vec = vector<long>();
    
    for (int i = 0; i < a; i++) {
        int tmp; cin >> tmp;
        vec.push_back(tmp);
        
        if (mx < tmp) mx = tmp;
        sum += tmp;
    }
    
    if (sum == 0) { cout << 0; return 0; }
    
    m = ((int)log10(mx) + 1) * 2;
    
    sort(vec.begin(), vec.end(), compare);
    
    for (int i = 0; i < vec.size(); i++) cout << vec.at(i);
    
    return 0;
}