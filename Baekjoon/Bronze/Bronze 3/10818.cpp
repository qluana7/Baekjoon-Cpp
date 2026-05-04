#include <iostream>

int main() {
    int min, max, n;
    
    std::cin >> n >> min;
    max = min;
    
    for (; --n;) {
        int x; std::cin >> x;
        max = std::max(max, x);
        min = std::min(min, x);
    }
    
    std::cout << min << " " << max;
    
    return 0;
}