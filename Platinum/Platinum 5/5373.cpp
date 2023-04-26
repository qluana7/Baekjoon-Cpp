#include <iostream>
#include <string>

using namespace std;

struct cube {
    char
    front[3][3] {
        { 'r', 'r', 'r' }, 
        { 'r', 'r', 'r' },
        { 'r', 'r', 'r' }
    },
    back[3][3] {
        { 'o', 'o', 'o' },
        { 'o', 'o', 'o' },
        { 'o', 'o', 'o' }
    },
    top[3][3] {
        { 'w', 'w', 'w' },
        { 'w', 'w', 'w' },
        { 'w', 'w', 'w' }
    },
    bottom[3][3] {
        { 'y', 'y', 'y' },
        { 'y', 'y', 'y' },
        { 'y', 'y', 'y' }
    },
    left[3][3] {
        { 'g', 'g', 'g' },
        { 'g', 'g', 'g' },
        { 'g', 'g', 'g' }
    },
    right[3][3] {
        { 'b', 'b', 'b' },
        { 'b', 'b', 'b' },
        { 'b', 'b', 'b' }
    };
    
    void rotate(char c);
};

void rt(char pace[3][3]) {
    char tmp[3] { pace[0][0], pace[0][1], pace[0][2] };
    
    pace[0][2] = pace[0][0];
    pace[0][1] = pace[1][0];
    pace[0][0] = pace[2][0];
    
    pace[0][0] = pace[2][0];
    pace[1][0] = pace[2][1];
    pace[2][0] = pace[2][2];
    
    pace[2][0] = pace[2][2];
    pace[2][1] = pace[1][2];
    pace[2][2] = pace[0][2];
    
    pace[2][2] = tmp[2];
    pace[1][2] = tmp[1];
    pace[0][2] = tmp[0];
}

void cube::rotate(char c) {
    switch (c) {
        case 'U': case 'D': {
            int fr;
            if (c == 'U') { rt(this->top);    fr = 0; }
            else          { rt(this->bottom); fr = 2; }
            char tmp[3] { back[fr][0], back[fr][1], back[fr][2] };
            
            back[fr][0] = left[fr][2];
            back[fr][1] = left[fr][1];
            back[fr][2] = left[fr][0];
            
            left[fr][0] = front[fr][0];
            left[fr][1] = front[fr][1];
            left[fr][2] = front[fr][2];
            
            front[fr][0] = right[fr][2];
            front[fr][1] = right[fr][1];
            front[fr][2] = right[fr][0];
            
            right[fr][0] = tmp[0];
            right[fr][1] = tmp[1];
            right[fr][2] = tmp[2];
            
            break;
        }
        case 'F': case 'B': {
            int fr;
            if (c == 'F') { rt(this->front); fr = 2; }
            else          { rt(this->back);  fr = 0; }
            char tmp[3] { top[fr][0], top[fr][1], top[fr][2] };
            
            top[fr][0] = left[2][fr];
            top[fr][1] = left[1][fr];
            top[fr][2] = left[0][fr];
            
            left[2][fr] = bottom[fr][2];
            left[1][fr] = bottom[fr][1];
            left[0][fr] = bottom[fr][0];
            
            bottom[fr][2] = right[0][fr];
            bottom[fr][1] = right[1][fr];
            bottom[fr][0] = right[2][fr];
            
            right[0][fr] = tmp[0];
            right[1][fr] = tmp[1];
            right[2][fr] = tmp[2];
            
            break;
        }
        case 'L': case 'R': {
            int fr;
            if (c == 'L') { rt(this->left);  fr = 0; }
            else          { rt(this->right); fr = 2; }
            char tmp[3] { top[0][fr], top[1][fr], top[2][fr] };
            
            top[0][fr] = back[2][fr];
            top[1][fr] = back[1][fr];
            top[2][fr] = back[0][fr];
            
            back[2][fr] = bottom[2][fr];
            back[1][fr] = bottom[1][fr];
            back[0][fr] = bottom[0][fr];
            
            bottom[2][fr] = front[0][fr];
            bottom[1][fr] = front[1][fr];
            bottom[0][fr] = front[2][fr];
            
            front[0][fr] = tmp[0];
            front[1][fr] = tmp[1];
            front[2][fr] = tmp[2];            
            break;
        }
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    
    while (n --> 0) {
        cube cb;
        int k; cin >> k;
        
        while (k --> 0) {
            string rotate; cin >> rotate;
            if (rotate[0] == 'D' || rotate[0] == 'B' || rotate[0] == 'R')
                rotate[1] = rotate[1] == '+' ? '-' : '+';
            int q = rotate[1] == '+' ? 1 : 3;
            for (int i = 0; i < q; i++)
                cb.rotate(rotate[0]);
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << cb.top[i][j];
            
            cout << "\n";
        }
    }
    
    return 0;
}