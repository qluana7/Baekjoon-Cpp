#include <iostream>

int main() {
    int a;
    
    std::cin >> a;
    
    std::cout << (a % 400 > 0 ? !(a % 4) & a % 100 > 0 ? 1 : 0 : 1);
    
    return 0;
}