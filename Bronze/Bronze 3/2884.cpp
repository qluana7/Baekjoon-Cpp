#include <iostream>

int main() {
    int h, m;
    
    std::cin >> h >> m;
    
    if ((m -= 45) < 0) { m += 60; h--; }
    
    if (h == -1) h = 23;
    else if (h == 24) h = 0;
    
    std::cout << h << " " << m;
    
    return 0;
}