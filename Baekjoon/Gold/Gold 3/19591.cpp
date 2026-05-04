#include <iostream>
#include <string>
#include <deque>

#define isNum(c) ('0' <= (c) && (c) <= '9')
#define asPri(c) ((c) == '*' || (c) == '/' ? 2 : 1)

using namespace std;

inline int priority(char a, char b) {
    return asPri(b) - asPri(a);
}

inline long long calc(long long a, char op, long long b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    string s; cin >> s;

    deque<long long> nd;
    deque<char> cd;
    bool isN = false, neg = false;
    int n = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i == 0 && s[0] == '-') continue;

        if (!isNum(s[i])) {
            nd.push_back(stoll(string(s.begin() + n, s.begin() + i)));
            cd.push_back(s[i]);
            n = i + 1;
        }
    }

    nd.push_back(stoll(string(s.begin() + n, s.end())));

    while (!cd.empty()) {
        char f = cd.front(), b = cd.back();

        int p = priority(f, b);

        long long
            _f = calc(nd.begin()[0], f, nd.begin()[1]),
            _b = calc(nd.end()[-2], b, nd.end()[-1]);

        if ((_f >= _b && p == 0) || p == -1) {
            nd.pop_front(); nd.pop_front();
            nd.push_front(_f);
            cd.pop_front();
        } else {
            nd.pop_back(); nd.pop_back();
            nd.push_back(_b);
            cd.pop_back();
        }
    }

    cout << nd.front();
}