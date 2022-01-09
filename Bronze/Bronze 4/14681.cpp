#include <iostream>

int main() {
    int a, b;
    
    std::cin >> a >> b;
    
    std::cout << (a < 0 ^ b < 0) + ((b < 0 ? 1 : 0) * 2 + 1);
    
    return 0;
}