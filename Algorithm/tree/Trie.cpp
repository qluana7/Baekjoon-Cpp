/*
 * Algorithm Name : Trie
 *
 * Description
 *    - 트라이 구현
 * 
 * Reference
 *    - ? (Missing reference)
 */

#include <string>
#include <vector>
#include <map>

using namespace std;

struct Node {
    Node() : children(map<char, Node*>{}) { };
    Node(const Node&) = default;
    Node(char k) : Node() { key = k; }
    ~Node() { for (auto [_, x] : children) if (x != nullptr) delete x; }

    char key = '\0'; bool data = false; int csz = 0;
    map<char, Node*> children;

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
    vector<int> find(const string& str) const;
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

vector<int> Trie::find(const string& str) const {
    vector<int> v;
    int n = 0;
    Node* current = this->head;

    for (auto x : str) {
        int p = x - 'a';
        
        if (current->data) v.push_back(n);
        if (current->children[p] == nullptr)
            break;

        current = current->children[p];
        n++;
    }

    return v;
}