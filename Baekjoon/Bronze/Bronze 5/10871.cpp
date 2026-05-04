#include <iostream>

int main() {
    int n, x;
    
    std::cin >> n >> x;
    
    for (; n--;) {
        int a; std::cin >> a;
        if (a < x) std::cout << a << " ";
    }
    
    return 0;
}