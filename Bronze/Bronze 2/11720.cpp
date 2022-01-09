#include <iostream>

int main() {
    int n, sum = 0; std::cin >> n;
    
    for (std::getchar(); n--;) {
        sum += std::getchar() - 48;
    }
    
    std::cout << sum;
    
    return 0;
}