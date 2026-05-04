#include <iostream>

int main() {
    double n, tmp, max = 0, sum;
    
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        sum += tmp;
        if (max < tmp) max = tmp;
    }
    
    std::cout << sum / max / n * 100;
    
    return 0;
}