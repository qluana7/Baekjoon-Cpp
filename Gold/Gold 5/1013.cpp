/*
FA table

# NFA (Figure 1)
      |  0  |    1   | ACT
--------------------------
   $7 | $7  | $7     |
 * $0 | $5  | $1     |
   $1 | $2  | $7     |
   $2 | $3  | $7     |
   $3 | $3  | $4     |
   $4 | $5  | $1, $4 |  O
   $5 | $7  | $6     |
   $6 | $5  | $1     |  O

# NFA -> DFA (Figure 2)
                 |       0        |       1         |    |       |  0  |  1  | ACT
----------------------------------------------------|    |-------------------------
  { q- }         | { q- }         | { q- }          |    |   $17 | $17 | $17 |
* { q0 }         | { q5 }         | { q1 }          |    | * $0  | $5  | $1  |
  { q1 }         | { q2 }         | { q- }          |    |   $1  | $2  | $17 |
  { q2 }         | { q3 }         | { q- }          |    |   $2  | $3  | $17 |
  { q3 }         | { q3 }         | { q4 }          |    |   $3  | $3  | $4  |
  { q4 }         | { q5 }         | { q1, q4 }      |    |   $4  | $5  | $7  |  O
  { q5 }         | { q- }         | { q6 }          |    |   $5  | $17 | $6  |
  { q6 }         | { q5 }         | { q1 }          | => |   $6  | $5  | $1  |  O
  { q1, q4 }     | { q2, q5 }     | { q-, q1, q4 }  |    |   $7  | $8  | $15 |  O
  { q2, q5 }     | { q-, q3 }     | { q-, q6 }      |    |   $8  | $9  | $12 |
  { q-, q3 }     | { q-, q3 }     | { q-, q4 }      |    |   $9  | $9  | $10 |
  { q-, q4 }     | { q-, q5 }     | { q-, q1, q4 }  |    |   $10 | $11 | $15 |  O
  { q-, q5 }     | { q- }         | { q-, q6 }      |    |   $11 | $17 | $12 |
  { q-, q6 }     | { q-, q5 }     | { q-, q1 }      |    |   $12 | $11 | $13 |  O
  { q-, q1 }     | { q-, q2 }     | { q- }          |    |   $13 | $14 | $17 |
  { q-, q2 }     | { q-, q3 }     | { q- }          |    |   $14 | $9  | $17 |
  { q-, q1, q4 } | { q-, q2, q5 } | { q-, q1, q4 }  |    |   $15 | $16 | $15 |  O
  { q-, q2, q5 } | { q-, q3 }     | { q-, q6 }      |    |   $16 | $9  | $12 |

Ref 1013.png
*/

#include <iostream>
#include <vector>

using namespace std;

class Machine {
public:
    Machine(
        const vector<vector<int>>& t,
        const vector<bool>& at,
        int init
    ) : table(t), actable(at), stat(init) { }

private:
    vector<vector<int>> table;
    vector<bool> actable;
    int stat;

public:
    void reset(int init)
    { stat = init; }

    void transfer(int inp)
    { stat = table[stat][inp]; }

    bool is_accepted() const
    { return actable[stat]; }
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    vector<vector<int>> table = {
        {  5,  1 }, {  2, 17 }, {  3, 17 }, {  3,  4 }, {  5,  7 }, { 17,  6 },
        {  5,  1 }, {  8, 15 }, {  9, 12 }, {  9, 10 }, { 11, 15 }, { 17, 12 },
        { 11, 13 }, { 14, 17 }, {  9, 17 }, { 16, 15 }, {  9, 12 }, { 17, 17 }, 
      };

    vector<bool> actable(table.size()); {
        actable[ 4] =
        actable[ 6] =
        actable[ 7] =
        actable[10] =
        actable[12] =
        actable[15] =
            true;
    };

    Machine m(table, actable, 0);

    int n; cin >> n;
    while (n --> 0) {
        string s; cin >> s;

        m.reset(0);
        for (auto c : s) m.transfer(c - '0');
        cout << (m.is_accepted() ? "YES" : "NO") << "\n";
    }
}