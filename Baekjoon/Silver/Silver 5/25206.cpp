#include <iostream>

using namespace std;

int main() {
    double d, t = 0; char s, p; int x = 0;
    for (; ~scanf("%*s %lf %c%c", &d, &s, &p); ) {
        if (s == 80 || (x += d, p == 10)) continue;
        t += d * ((69 - s) + 0.5 * !(p - 43));
    }
    
    cout << t / x;
    
    return 0;
}