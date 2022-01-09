#include <iostream>

int main() {
    int n, table[46] { 0, 1, }; std::cin >> n;
    
    for (int i = 2; i <= n; i++)
        table[i] = table[i - 1] + table[i - 2];
    
    std::cout << table[n];
}