/*
 * Algorithm Name : Longest Common Subsequence (LCS)
 *
 * Description
 *    - 최장 공통 부분 수열 알고리즘
 *    - 시간 복잡도 : O(N * M)
 * 
 * Reference
 *    - https://ko.wikipedia.org/wiki/%EC%B5%9C%EC%9E%A5_%EA%B3%B5%ED%86%B5_%EB%B6%80%EB%B6%84_%EC%88%98%EC%97%B4
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

template <typename T>
vector<vector<int>> LCS(const T& v1, const T& v2) {
    vector<vector<int>> out(v2.size(), vector<int>(v1.size(), 0));
    
    for (int i = 1; i < v1.size() - 1; i++) {
        for (int j = 1; j < v2.size() - 1; j++) {
            if (v1[i] == v2[j]) out[i][j] = out[i - 1][j - 1] + 1;
            else out[i][j] = max(out[i][j - 1], out[i - 1][j]);
        }
    }
    
    return out;
}

int LCS_LEN(const string& v1, const string& v2) {
    vector<vector<int>> out(v2.size(), vector<int>(v1.size(), 0));
    
    for (int i = 1; i < v1.size(); i++) {
        for (int j = 1; j < v2.size(); j++) {
            if (v1[i] == v2[j]) out[i][j] = out[i - 1][j - 1] + 1;
            else out[i][j] = max(out[i][j - 1], out[i - 1][j]);
        }
    }
    
    return out[v1.size() - 1][v2.size() - 1];
}

string LCS_REV(const string& v1, const string& v2) {
    vector<vector<int>> out(v2.size(), vector<int>(v1.size(), 0));
    
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
    
    return str;
}