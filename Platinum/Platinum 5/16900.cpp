#include <vector>
#include <string>
#include <iostream>

#define ll long long

using namespace std;

vector<ll> init(string str) {
    vector<ll> res(str.size(), 0);
    
    for (ll i = 1, j = 0; i < res.size(); i++) {
        while (j > 0 && str[i] != str[j]) j = res[j - 1];
        
        if (str[i] == str[j]) res[i] = ++j;
    }
    
    return res;
}

int main() {
    string str; int n; cin >> str >> n;
    
    auto v = init(str);
    
    cout << str.size() * n - v.back() * (n - 1);
    
    return 0;
}