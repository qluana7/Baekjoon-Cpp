/*
 * Algorithm Name : Mo's
 *
 * Description
 *    - 업데이트 없이 조회만 가능한 쿼리에 대해서 쓰는 알고리즘
 *    - 쿼리를 잘 정렬해 이전 값을 이용해 답을 구하는 알고리즘
 * 
 *    - 적당한 수 K를 잡는다.
 *    - K는 sqrt decomposition에 의해 sqrt(N)으로 한다. (N은 배열의 크기)
 *    - [L, R]에서 floor(L/K)에 대해 오름차순으로 정렬
 *    - 같은 경우 floor(R/K)에 대해 오름차순으로 정렬
 *    - 정렬 이후 이전 값을 기억하여 그 값을 기준으로
 *    - 앞 뒤 포인터를 움직여 답을 구함
 * 
 * Reference
 *    - https://justicehui.github.io/hard-algorithm/2019/06/17/MoAlgorithm/
 * 
 * Test Problem Number
 *    - https://www.acmicpc.net/problem/11659
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Query {
    int index, l, r;
};

int main() {
    int n, m, k; cin >> n >> m; k = sqrt(n);
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    
    vector<Query> query(m);
    for (int i = 0; i < m; i++) { cin >> query[i].l >> query[i].r; query[i].index = i; }
    
    sort(query.begin(), query.end(), [k](const Query& a, const Query& b) {
        int l1 = a.l / k, l2 = b.l / k;
        if (l1 != l2) return l1 < l2;
        else return a.r < b.r;
    });
    
    vector<int> output(m);
    int l = query[0].l, r = query[0].r;
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += v[i - 1];
    }
    output[query[0].index] = sum;
    
    for (int i = 1; i < query.size(); i++) {
        auto _l = query[i].l, _r = query[i].r;
        
        while (_l < l) { l--; sum += v[l - 1]; }
        while (_r > r) { r++; sum += v[r - 1]; }
        while (_l > l) { sum -= v[l - 1]; l++; }
        while (_r < r) { sum -= v[r - 1]; r--; }
        
        output[query[i].index] = sum;
    }
    
    for (auto x : output) cout << x << "\n";
}