#include <iostream>

int main() {
    int n; std::cin >> n;
    
    for (; n--;) {
        int a, b;
        std::cin >> a >> b;
        
        std::cout << a + b << std::endl;
    }
    
    return 0;
}