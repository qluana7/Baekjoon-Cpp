#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int A = 0;

void program(vector<char>& code) {
    int PC = 0;
    while (1) {
        char d = code[PC]; PC++;
        if (PC == code.size()) PC = 0;
        
        switch ((d >> 5) & 0x7) {
            case 0: code[d & 0x1f] = A; break;
            case 1: A = code[d & 0x1f]; break;
            case 2: if (A == 0) PC = d & 0x1f; break;
            case 3: break;
            case 4: A--; break;
            case 5: A++; break;
            case 6: PC = d & 0x1f; break;
            case 7: return;
        }
    }
}

int main() {
    do {
        string str; vector<char> v(32);
        for (int i = 0; i < 32; i++) {
            cin >> str;
            if (cin.eof()) return 0;
            v[i] = stoi(str, nullptr, 2);
        }
        
        A = 0;
        program(v);
    
        cout << bitset<8>(A) << "\n";
    } while (!cin.eof());
}