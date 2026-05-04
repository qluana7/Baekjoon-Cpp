#include <iostream>

int main() {
    int n; std::cin >> n;
    for (; n--;) {
        int arr[6];
        for (int i = 0; i < 6; i++)
            std::cin >> arr[i];
        
        int a, b, c, p, q;
        a = arr[3] - arr[0]; b = arr[4] - arr[1];
        c = a * a + b * b;
        
        p = arr[5] + arr[2];
        q = arr[5] - arr[2];
        
        std::cout << (!a && !b && !q ? -1 : c > p * p || c < q * q ? 0 : c == p * p || c == q * q ? 1 : 2) << std::endl;
    }
}