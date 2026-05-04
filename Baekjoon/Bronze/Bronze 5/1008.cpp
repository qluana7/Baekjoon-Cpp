#include <iostream>

int main() {
    double a, b;
    
    std::cout.precision(11);
    
    std::cin >> a >> b;
    std::cout << a / b;
    
    return 0;
}