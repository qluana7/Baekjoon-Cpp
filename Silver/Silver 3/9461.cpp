#include <iostream>

int main() {
    unsigned long table[101] { 1, 1, 1, };
    int f; std::cin >> f;
    
    for (; f--;) {
        int n; std::cin >> n;
        
        for (int i = 3; i < n; i++)
            table[i] = table[i - 2] + table[i - 3];
        
        std::cout << table[n - 1] << std::endl;
    }
}