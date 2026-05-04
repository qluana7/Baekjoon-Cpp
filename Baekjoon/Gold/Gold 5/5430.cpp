#include <iostream>
#include <sstream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    for (; n-- ;) {
        string cmd, tmp;
        deque<int> d;
        int count;
        
        cin >> cmd >> count >> tmp;
        tmp = tmp.substr(1, tmp.size() - 2);
        
        stringstream ss(tmp);
        string t;
        
        while (getline(ss, t, ',')) d.push_back(stoi(t));
        
        bool a = 1, b = 0;
        
        for (char& c : cmd) {
            if (c == 'R') a = !a;
            else {
                if (d.size() == 0) { b = 1; break; }
                if (a) d.pop_front();
                else d.pop_back();
            }
        }
        
        if (b) { cout << "error\n"; continue; }
        if (d.size() == 0) { cout << "[]\n"; continue; }
        
        cout << '[';
        if (!a) reverse(d.begin(), d.end());
        
        for (int i = 0; i < d.size() - 1; i++) cout << d.at(i) << ",";
        cout << d.at(d.size() - 1) << "]" << "\n";
    }
}