#include <iostream>

int main() {
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        int n;
        
        std::cin >> n;
        
        sum += n * n;
    }
    
    std::cout << sum % 10;
    
    return 0;
}