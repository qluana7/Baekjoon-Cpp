#include <iostream>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    
    if (a + b + c >= 100) cout << "OK";
    else cout << (a > b ? b > c ? "Hanyang" : "Korea" : a > c ? "Hanyang" : "Soongsil");
    
    return 0;
}