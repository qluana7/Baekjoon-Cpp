#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    Trie color;
    unordered_set<string> name;

    int n, m; cin >> n >> m; string str;
    while (n --> 0) { cin >> str; color.insert(str); }
    while (m --> 0) { cin >> str; name.insert(str);  }

    cin >> n;
    while (n --> 0) {
        cin >> str;

        bool flag = false;
        for (auto t : color.find(str)) {
            if (t == -1 || !name.count(str.substr(t))) continue;
            flag = true;
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
}