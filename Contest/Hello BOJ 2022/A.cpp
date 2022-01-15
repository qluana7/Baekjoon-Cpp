#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

#define long unsigned long

using namespace std;

long toN(long num, int base) {
    deque<long> d;
    
    do {
        d.push_back(num % base);
    } while (num /= base);
    
    long out = 0, b = 1, s = d.size();
    
    for (int i = 0; i < s; i++) {
        out += d.front() * b;
        d.pop_front(); b *= 10;
    }
    
    return out;
}

long to10(long num, int base) {
    long out = 0, b = 1;
    
    do {
        out += num % 10 * b;
        b *= base;
    } while (num /= 10);
    
    return out;
}

long vtoi(vector<long> v) {
    long out = 0;
    for (long& n : v) {
        out *= 10;
        out += n;
    }
    
    return out;
}

int main() {
    long n, base; cin >> n >> base;
    
    long comp = toN(n, base), d;
    vector<long> data({1, 0});
    
    for (int i = 2; i < base; i++) {
        data.push_back(i);
    }
    
    do {
        if (comp < (d = vtoi(data))) { cout << d << endl << to10(d, base); return 0; }
    } while (next_permutation(data.begin(), data.end()));
    
    cout << -1;
    
    return 0;
}