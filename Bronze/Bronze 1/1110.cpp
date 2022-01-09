#include <iostream>

int main() {
    int n, x, c = 0; std::cin >> n; x = n;
    
    do {
        int a = x / 10, b = x % 10;
        x = b * 10 + (a + b) % 10;
        c++;
    } while(x != n);
    
    std::cout << c;
    
    return 0;
}