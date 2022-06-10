#include <iostream>
#include <iomanip>

int main() {
    int n;
    
    std::string s = "";
    
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
        std::cout << std::setw(n) << (s += "*") << std::endl;
    
    return 0;
}