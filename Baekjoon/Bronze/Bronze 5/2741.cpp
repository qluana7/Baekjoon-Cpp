#include <iostream>

int main() {
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    int n; std::cin >> n;
    
    for (int i = 1; i <= n; i++)
        std::cout << i << "\n";
    
    return 0;
}