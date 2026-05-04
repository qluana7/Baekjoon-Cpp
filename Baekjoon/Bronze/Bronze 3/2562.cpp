#include <iostream>

int main() {
    int max = 0, maxi = 0;
    
    for (int i = 0; i < 9; i++) {
        int n;
        std::cin >> n;
        
        if (max < n) { max = n; maxi = i; }
    }
    
    std::cout << max << std::endl << maxi + 1;
    
    return 0;
}