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
#include <map>
#include <unordered_set>

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

    int find(const string& str) const;
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