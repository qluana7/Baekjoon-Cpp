#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    string input;
    while (getline(cin, input)) {
        if (input == "#") break;

        string tmp; stack<string> s;
        stringstream ss(input);
        while (!getline(ss, tmp, '<').eof()) {
            getline(ss, tmp, '>');

            if (tmp[tmp.size() - 1] == '/') continue;
            else if (tmp[0] == '/') {
                if (s.empty()) { s.push("illegal"); break; }

                auto b = tmp.begin() + 1;
                while (*b != ' ' && b != tmp.end()) b++;
                if (s.top() != string(tmp.begin() + 1, b)) break;

                s.pop();
            } else {
                auto b = tmp.begin();
                while (*b != ' ' && b != tmp.end()) b++;
                s.push(string(tmp.begin(), b));
            }
        };

        if (!s.empty()) cout << "il";
        cout << "legal\n";
    }
}