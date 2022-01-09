#include <iostream>

int main() {
    int a, b, i, j;
    
    std::cin >> i;
    
    for (; i--;) {
        std::cin >> a >> b; b -= a;
        
        for (j = 1; (b -= j * 2) >= 0; j++);
        std::cout << (j - 1) * 2 + 2 + b / j << std::endl;
    }
}