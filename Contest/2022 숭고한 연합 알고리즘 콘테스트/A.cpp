#include <iostream>

using namespace std;

int main() {
    char c = getchar();
    
    cout << (c == 'n' || c == 'N' ? "Naver D2" : "Naver Whale");
    
    return 0;
}