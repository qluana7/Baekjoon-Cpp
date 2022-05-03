#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v { 0, 1, 2 };
    
    for (int i = 2; i < n; i++)
        v.push_back((v[i] + v[i - 1]) % 15746);
    
    cout << v[n];
    
    return 0;
}