#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n; std::cin >> n;
    
    for(; n; n--) std::cout << n << "\n";
    
    return 0;
}