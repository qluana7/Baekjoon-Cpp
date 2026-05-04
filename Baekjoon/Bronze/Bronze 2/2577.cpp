#include <iostream>

int main() {
    int arr[10] = {};
    int a, b, c;
    
    std::cin >> a >> b >> c;
    
    a *= b * c;
    
    for (char& c : std::to_string(a))
        arr[c - 48]++;
    
    for (int& n : arr) std::cout << n << std::endl;
    
    return 0;
}