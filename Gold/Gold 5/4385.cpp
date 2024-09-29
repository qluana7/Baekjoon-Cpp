#include <iostream>
#include <vector>

using namespace std;

vector<int> ram(1000);
vector<int> reg(10);

int run() {
    int inst = 0;
    for (auto rb = ram.begin(); ; rb++) {
        inst++;
        int op1 = *rb / 10 % 10, op2 = *rb % 10;
        switch (*rb / 100) {
            case 1: return inst;
            case 2: reg[op1] = op2;                                  break;
            case 3: reg[op1] = (reg[op1] + op2) % 1000;              break;
            case 4: reg[op1] = (reg[op1] * op2) % 1000;              break;
            case 5: reg[op1] = reg[op2];                             break;
            case 6: reg[op1] = (reg[op1] + reg[op2]) % 1000;         break;
            case 7: reg[op1] = (reg[op1] * reg[op2]) % 1000;         break;
            case 8: reg[op1] =  ram[reg[op2]];                       break;
            case 9: ram[reg[op2]] =  reg[op1];                       break;
            case 0: rb = reg[op2] ? ram.begin() + reg[op1] - 1 : rb; break;
        }
    }
}

int main() {
    int x;
    for (auto rb = ram.begin(); cin >> x; rb++) { *rb = x; }
    
    cout << run();
}