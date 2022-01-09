#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    for (; n--;) {
        int x;
        std::string str;
        
        std::cin >> x >> str;
        
        for (char& c : str) std::cout << std::string(x, c);
        
        std::cout << std::endl;
    }
    
    return 0;
}