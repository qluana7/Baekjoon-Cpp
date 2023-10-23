#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

#define psi pair<string, int>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    map<string, int> k;
    
    while (n --> 0) {
        string str; cin >> str;
        if (str.size() < m) continue;
        k[str]++;
    }
    
    vector<psi> v(k.begin(), k.end());
    sort(v.begin(), v.end(), [](const psi& a, const psi& b) {
        if (a.second != b.second) return a.second > b.second;
        else if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
        else return a.first < b.first;
    });
    
    for (const auto& x : v) cout << x.first << "\n";
    
    return 0;
}