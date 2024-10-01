#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node {
    Node() : children(vector<Node*>(26, nullptr)) { };
    Node(const Node&) = default;
    Node(char k) : Node() { key = k; }
    ~Node() { for (auto x : children) if (x != nullptr) delete x; }

    char key = '\0'; bool data = false; Node* fail = nullptr; int csz = 0;
    vector<Node*> children;

    void insert(char t) { children[t - 'a'] = new Node(t); csz++; }
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
    
    bool find(const string& src) const;
};

void Trie::ConstructFail() {
    queue<Node*> q;
    this->head->fail = this->head;
    q.push(this->head);

    while (!q.empty()) {
        Node* cp = q.front(); q.pop();

        for (int i = 0; i < 26; i++) {
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
        int p = x - 'a';
        if (current->children[p] == nullptr)
            current->insert(x);

        current = current->children[p];
    }
    
    current->data = 1;
}

bool Trie::find(const string& src) const {
    Node* cp = this->head;

    bool found = false;

    for (int i = 0; i < src.size(); i++) {
        int pos = src[i] - 'a';
        while (cp != this->head && cp->children[pos] == nullptr)
            cp = cp->fail;
        
        if (cp->children[pos] != nullptr)
            cp = cp->children[pos];
        
        if (cp->data)
            found = true;
    }

    return found;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    Trie t;
    
    string str; int n; cin >> n;

    while (n --> 0) {
        cin >> str;
        t.insert(str);
    }

    t.ConstructFail();

    cin >> n;

    while (n --> 0) {
        cin >> str;
        cout << (t.find(str) ? "YES" : "NO") << "\n";
    }
}