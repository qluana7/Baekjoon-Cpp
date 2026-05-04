#include <iostream>
#include <algorithm>

using namespace std;

#define num(x) ((x) + ((x) >= 10 ? 55 : 48))

int main() {
    int n, base; cin >> n >> base;
    
    string str;
    while (n / base) {
        str += num(n % base); n /= base;
    } str += num(n);
    
    reverse(str.begin(), str.end());
    cout << str;
    
    return 0;
}