#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int GET(char c) {
    switch (c) {
        case 'A': return 0;
        case 'G': return 1;
        case 'T': return 2;
        case 'C': return 3;
    }
}

struct Node {
    Node() : children(vector<Node*>(4, nullptr)) { };
    Node(const Node&) = default;
    Node(char k) : Node() { key = k; }
    ~Node() { for (auto x : children) if (x != nullptr) delete x; }

    char key = '\0'; bool data = false; Node* fail = nullptr; int csz = 0;
    vector<Node*> children;

    void insert(char t) { children[GET(t)] = new Node(t); csz++; }
};

class Trie {
public:
    Trie() : head(new Node()) { }
    Trie(const Trie&) = default;
    ~Trie() { delete head; }

private:
    Node* head;

public:
    void ConstructFail();
    void insert(const string& str);
    
    int find(const string& src) const;
};

void Trie::ConstructFail() {
    queue<Node*> q;
    this->head->fail = this->head;
    q.push(this->head);

    while (!q.empty()) {
        Node* cp = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            Node* np = cp->children[i];

            if (np == nullptr) continue;
            if (cp == this->head) np->fail = this->head;
            else {
                Node* f = cp->fail;

                while (f != this->head && f->children[i] == nullptr)
                    f = f->fail;
                
                if (f->children[i] != nullptr) f = f->children[i];

                np->fail = f;
            }

            if (np->fail->data) np->data = true;

            q.push(np);
        }
    }
}

void Trie::insert(const string& str) {
    Node* current = this->head;
    for (auto x : str) {
        int p = GET(x);
        if (current->children[p] == nullptr)
            current->insert(x);

        current = current->children[p];
    }
    
    current->data = 1;
}

int Trie::find(const string& src) const {
    Node* cp = this->head;

    int found = 0;

    for (int i = 0; i < src.size(); i++) {
        int pos = GET(src[i]);
        while (cp != this->head && cp->children[pos] == nullptr)
            cp = cp->fail;
        
        if (cp->children[pos] != nullptr)
            cp = cp->children[pos];
        
        if (cp->data)
            found++;
    }

    return found;
}

void solve() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    Trie t;
    
    int n, m; cin >> n >> m;
    string dna, mark; cin >> dna >> mark;

    for (int a = 0; a <= m; a++) {
        for (int b = a + 2; b <= m; b++) {
            reverse(mark.begin() + a, mark.begin() + b);
            t.insert(mark);
            reverse(mark.begin() + a, mark.begin() + b);
        }
    }

    t.insert(mark);

    t.ConstructFail();

    cout << t.find(dna) << "\n";
}

int main() {
    int n; cin >> n;

    while (n --> 0) solve();
}