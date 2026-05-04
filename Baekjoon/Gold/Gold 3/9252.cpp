#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    string v1, v2; cin >> v1 >> v2;
    v1 = " " + v1;
    v2 = " " + v2;
    
    vector<vector<int>> out(v1.size(), vector<int>(v2.size(), 0));
    
    for (int i = 1; i < v1.size(); i++) {
        for (int j = 1; j < v2.size(); j++) {
            if (v1[i] == v2[j]) out[i][j] = out[i - 1][j - 1] + 1;
            else out[i][j] = max(out[i][j - 1], out[i - 1][j]);
        }
    }
    
    string str;
    stack<char> st;
    
    int x = v1.size() - 1, y = v2.size() - 1;
    while (out[x][y] != 0) {
        if (v1[x] == v2[y]) {
            st.push(v1[x]); x--; y--;
        } else {
            if (out[x][y - 1] >= out[x - 1][y]) y--;
            else x--;
        }
    }
    
    while (!st.empty()) {
        char x = st.top(); st.pop();
        str.push_back(x);
    }
    
    cout << out[v1.size() - 1][v2.size() - 1] << "\n" << str;
    
    return 0;
}