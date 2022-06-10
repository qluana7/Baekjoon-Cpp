#include <iostream>

int main() {
    int a = 0, x; std::cin >> x;
    
    for (int i = 1; i <= x; i++) a += i;
    
    std::cout << a;
    
    return 0;
}