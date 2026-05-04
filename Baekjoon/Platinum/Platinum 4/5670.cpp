#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node() : children(vector<Node*>(26, nullptr)) { };
    Node(const Node&) = default;
    Node(char k) : Node() { key = k; }
    ~Node() { for (auto x : children) if (x != nullptr) delete x; }

    char key = '\0'; bool data = false; int csz = 0;
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
    void insert(const string& str);
    int count(const string& str) const;

    int get(const string& str) const;
};

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

int Trie::count(const string& str) const {
    Node* current = this->head;
    for (auto x : str) {
        int p = x - 'a';
        if (current->children[p] == nullptr)
            return 0;

        current = current->children[p];
    }
    
    return current->data;
}

int Trie::get(const string& str) const {
    int cnt = 0;
    Node* current = this->head;
    for (auto x : str) {
        int p = x - 'a';
        current = current->children[p];
        
        if (current->csz > 1 || current->data) cnt++;
    }

    return cnt;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        Trie trie;
        vector<string> v(n);
        for (auto& x : v) { cin >> x; trie.insert(x); }

        int sum = 0;
        for (auto& x : v) sum += trie.get(x);

        cout.precision(2);
        cout << fixed << (sum * 1.0 / v.size()) << "\n";
    }
}