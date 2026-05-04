#include <iostream>
#include <string>

int main() {
    std::string str; std::getline(std::cin, str);
    
    std::cout
        << (str == "1 2 3 4 5 6 7 8" ? "ascending"  :
            str == "8 7 6 5 4 3 2 1" ? "descending" : "mixed");
    
    return 0;
}