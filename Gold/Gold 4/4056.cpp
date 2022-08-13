#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<pair<int, int>> vp;

bool check(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (v[i][y] == n) return false;
        if (v[x][i] == n) return false;
    }
    
    for (int i = 0, m1 = x / 3 * 3; i < 3; i++)
        for (int j = 0, m2 = y / 3 * 3; j < 3; j++)
            if (v[i+m1][j+m2] == n) return false;
    
    return true;
}

bool solve(int x, int y, int n, int id) {
    if (!check(x, y, n)) return false;
    
    v[x][y] = n;
    
    if (id == vp.size()) return true;
    
    for (int i = 1; i <= 9; i++) {
        if (solve(vp[id].first, vp[id].second, i, id + 1)) return true;
    }
    
    v[x][y] = 0;
    return false;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    for (;n--; cout << "\n") {
        v = vector<vector<int>>(9, vector<int>(9));
        vp.clear();
        
        bool ch = false;
        
        for (int i = 0; i < 9; i++) {
            int checka[9] { 0, };
            for (int j = 0; j < 9; j++) {
                char tc; cin >> tc;
                v[i][j] = tc - 48;
                
                if (v[i][j] != 0) {
                    if (checka[v[i][j] - 1]) ch = true;
                    else checka[v[i][j] - 1]++;
                }
                
                if (v[i][j] == 0) vp.emplace_back(i, j);
            }
        }
        
        if (ch) { cout << "Could not complete this grid.\n"; continue; }
        
        ch = false;
        for (int i = 0; i < 9; i++) {
            int checka[9] { 0, };
            for (int j = 0; j < 9; j++) {
                if (v[i][j] != 0) {
                    if (checka[v[i][j] - 1]) { ch = true; break; }
                    else checka[v[i][j] - 1]++;
                }
            }
            
            if (ch) break;
        }
        
        if (ch) { cout << "Could not complete this grid.\n"; continue; }
        
        ch = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int checka[9] { 0, };
                
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (v[i*3+k][j*3+l] != 0) {
                            if (checka[v[i*3+k][j*3+l] - 1]) { ch = true; goto end; }
                            else checka[v[i*3+k][j*3+l] - 1]++;
                        }
                    }
                }
            }
        }
        
        end:
        if (ch) { cout << "Could not complete this grid.\n"; continue; }
        
        bool b = false;
        for (int i = 1; i <= 9; i++) if (b = solve(vp[0].first, vp[0].second, i, 1)) break;
        
        if (b) for (auto& vx : v) { for(auto x : vx) cout << x; cout << "\n"; }
        else cout << "Could not complete this grid.\n"; continue;
    }
    
    return 0;
}