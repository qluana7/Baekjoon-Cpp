#include <iostream>

int main() {
    int n;
    
    std::string s = "";
    
    std::cin >> n;
    
    for(; n--;) std::cout << (s += "*") << std::endl;
    
    return 0;
}