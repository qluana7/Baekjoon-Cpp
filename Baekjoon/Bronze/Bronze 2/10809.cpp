#include <iostream>
#include <string>

int main() {
    std::string str; std::cin >> str;
    
    for (char i = 'a'; i <= 'z'; i++)
        std::cout << (int)str.find(i) << " ";
    
    return 0;
}