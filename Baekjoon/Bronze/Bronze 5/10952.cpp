#include <iostream>

int main() {
    int a, b;
    
    for (; std::cin >> a >> b, a;) {
        
        std::cout << a + b << std::endl;
    }
    
    return 0;
}