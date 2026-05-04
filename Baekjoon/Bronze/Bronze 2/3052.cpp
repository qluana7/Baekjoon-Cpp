#include <iostream>

int main() {
    int arr[42] = {};
    int count = 0;
    
    for (int i = 0; i < 10; i++) {
        int n; std::cin >> n;
        
        if (arr[n % 42] == 0) {
            count++;
            arr[n % 42]++;
        }
    }
    
    std::cout << count;
    
    return 0;
}