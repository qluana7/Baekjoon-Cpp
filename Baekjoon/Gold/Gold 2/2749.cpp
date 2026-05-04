#include <iostream>
#include <vector>

#define llong long long

using namespace std;

int main() {
    int const DIV = 1000000;
    int const LEN = 1500000;
    
    llong n; cin >> n;
    vector<llong> table({ 0, 1 });
    
    for (int i = 2; i <= n % LEN; i++)
        table.push_back((table[i - 1] + table[i - 2]) % DIV);
    
    cout << table[n % LEN];
    
    return 0;
}