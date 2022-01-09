#include <iostream>

int main() {
    int a;
    
    std::cin >> a;
    
    std::cout
        << (a < 90 ? a < 80 ? a < 70 ? a < 60 ? "F" : "D" : "C" : "B" : "A");
    
    return 0;
}