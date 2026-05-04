#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using u64 = unsigned long long;
using i64 = long long;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int h, w; cin >> h >> w;
    
    vector<string> v(h);
    for (auto& s : v) cin >> s;
    
    int cnt = 0;
    
    for (int h1 = 0; h1 < h; h1++) {
        for (int h2 = h1; h2 < h; h2++) {
            for (int w1 = 0; w1 < w; w1++) {
                for (int w2 = w1; w2 < w; w2++) {
                    
                    cnt += [&] {
                        for (int i = h1; i <= h2; i++) {
                            for (int j = w1; j <= w2; j++) {
                                if (v[i][j] != v[h1 + h2 - i][w1 + w2 - j])
                                    return false;
                            }
                        }
                        
                        return true;
                    }();
                    
                }
            }
        }
    }
    
    cout << cnt;
}