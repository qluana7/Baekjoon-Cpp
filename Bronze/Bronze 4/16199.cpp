#include <iostream>

using namespace std;

struct date {
    int year, month, day;
};

int main() {
    date d1, d2;
    cin >> d1.year >> d1.month >> d1.day
        >> d2.year >> d2.month >> d2.day;
    
    int n = d2.year - d1.year;
    
    int a = n;
    if (d1.month == d2.month) {
        if (d1.day > d2.day) a--;
    } else if (d1.month > d2.month) a--;
    
    cout << a << "\n" << n + 1 << "\n" << n;
    
    return 0;
}