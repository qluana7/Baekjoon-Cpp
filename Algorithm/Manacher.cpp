/*
 * Algorithm Name : Manacher's Algorithm
 *
 * Description
 *    - 팰린드롬 판별 알고리즘 O(N)
 * 
 * Reference
 *    - https://www.crocus.co.kr/1075
 */

#include <string>
#include <vector>

using namespace std;

vector<int> manacher(const string& src) {
    string s = "#";

    for (auto c : src) s += c + (string)"#";

    int r = 0, t = 0, n = s.size();
    vector<int> ret(n);

    for (int i = 0; i < n; i++) {
        if (i <= r) ret[i] = min(ret[(t << 1) - i], r - i);
        else        ret[i] = 0;

        while (
            i - ret[i] - 1 >= 0 && i + ret[i] + 1 < n &&
            s[i - ret[i] - 1] == s[i + ret[i] + 1]
            ) ret[i]++;

        if (i + ret[i] > r) { r = i + ret[i]; t = i; }
    }

    return ret;
}