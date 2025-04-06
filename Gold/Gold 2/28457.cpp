#include <iostream>
#include <vector>
#include <functional>

#include <cstdint>

#define i32 int32_t
#define i64 int64_t

using namespace std;

i64 sz, cash, pay, mxsz;

i64 pos = 0, dcash = 0, cpos = 0;
bool prison = false; i32 pcount = 0;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    i64 g;
    cin >> sz >> cash >> pay >> g; mxsz = sz * 4 - 4;
    vector<function<void ()>> board(mxsz), card(g);
    vector<i64> prices(mxsz), gold(g);
    vector<bool> flags(mxsz);

    for (i32 i = 0; i < g; i++) {
        i64 a, b; cin >> a >> b;

        gold[i] = b;
        switch (a) {
            case 1: card[i] = [&] { cash  += gold[cpos]; }; break;
            case 2: card[i] = [&] {
                cash -= gold[cpos];
                if (cash < 0) exit(!(cout << "LOSE"));
            }; break;
            case 3: card[i] = [&] {
                dcash += gold[cpos];
                cash -= gold[cpos];
                if (cash < 0) exit(!(cout << "LOSE"));
            }; break;
            case 4: card[i] = [&] {
                pos += gold[cpos];
                if (pos >= mxsz) cash += pay * (pos / mxsz), pos %= mxsz;
                board[pos]();
            }; break;
        }
    }

    board[0] = [&] { cash += pay; };
    board[sz - 1] = [&] { prison = true; };
    board[sz * 2 - 2] = [&] { cash += dcash; dcash = 0; };
    board[sz * 3 - 3] = [&] { pos = 0; cash += pay; };

    flags[0] = flags[sz - 1] = flags[sz * 2 - 2] = flags[sz * 3 - 3] = true;

    for (i32 i = 1; i < mxsz; i++) {
        if (flags[i]) continue;

        char c; i64 k; cin >> c;

        if (c == 'G') {
            board[i] = [&] {
                card[cpos]();
                if (++cpos == g)
                    cpos = 0;
            }; flags[i] = true;
        } else {
            cin >> k;

            prices[i] = k;
            board[i] = [&] {
                if (flags[pos] || cash < prices[pos]) return;

                flags[pos] = true; cash -= prices[pos];
            };
        }
    }

    i32 n; cin >> n;

    while (n --> 0) {
        i32 d1, d2; cin >> d1 >> d2;

        if (prison) {
            if (d1 == d2 || ++pcount == 3)
                prison = false, pcount = 0;
            continue;
        }

        pos += d1 + d2;

        if (pos >= mxsz) cash += pay * (pos / mxsz), pos %= mxsz;

        board[pos]();
    }

    bool win = true;

    for (auto b : flags)
        win &= b;
    
    cout << (win ? "WIN" : "LOSE");
}