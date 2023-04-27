#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

struct Node {
    Node() = default;
    Node(const Node&) = default;
    Node(const string& v) : parent(nullptr), value(v) { }
    Node(Node* p, const string& v) : parent(p), value(v) { }
    Node* parent;
    map<string, Node*> album = {};
    map<string, Node*> photo = {};
    
    string value;
    
    void free() { pair<int, int> tmp; free(tmp); }
    
    void free(pair<int, int>& counts) {
        for (auto [_, node] : album) { counts.first++;  node->free(counts); }
        for (auto [_, node] : photo) { counts.second++; node->free(counts); }
        
        delete this;
    }
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    Node* album; Node* current = new Node("album");
    album = current;
    
    int n; cin >> n;
    
    while(n --> 0) {
        string cmd, name; cin >> cmd >> name;
        
        if (cmd == "mkalb") {
            if (current->album.count(name))
                cout << "duplicated album name\n";
            else {
                Node* node = new Node(current, name);
                current->album[name] = node;
            }
        } else if (cmd == "rmalb") {
            pair<int, int> cts { 0, 0 };
            if (name == "-1" || name == "0" || name == "1") {
                int num = stoi(name);
                
                switch (num) {
                    case 0: {
                        for (auto [_, node] : current->album) { cts.first++; node->free(cts); }
                        current->album = {};
                        break;
                    }
                    case -1:
                        if (!current->album.empty()) {
                            current->album.begin()->second->free(cts);
                            current->album.erase(current->album.begin());
                            cts.first++;
                        }
                        break;
                    case 1:
                        if (!current->album.empty()) {
                            prev(current->album.end())->second->free(cts);
                            current->album.erase(prev(current->album.end()));
                            cts.first++;
                        }
                        break;
                }
                
            } else {
                if (current->album.count(name)) {
                    current->album[name]->free(cts);
                    current->album.erase(name);
                    cts.first++;
                }
            }
            
            cout << cts.first << " " << cts.second << "\n";
        } else if (cmd == "insert") {
            if (current->photo.count(name))
                cout << "duplicated photo name\n";
            else {
                Node* node = new Node(current, name);
                current->photo[name] = node;
            }
        } else if (cmd == "delete") {
            int cts = 1;
            if (name == "-1" || name == "0" || name == "1") {
                int num = stoi(name);
                
                switch (num) {
                    case 0: {
                        cts--;
                        for (auto [_, node] : current->photo) { cts++; node->free(); }
                        current->photo = {};
                        break;
                    }
                    case -1:
                        if (current->photo.empty()) cts = 0;
                        else current->photo.erase(current->photo.begin());
                        break;
                    case 1:
                        if (current->photo.empty()) cts = 0;
                        else current->photo.erase(prev(current->photo.end()));
                        break;
                }
            } else {
                if (!current->photo.count(name)) cts = 0;
                else current->photo.erase(name);
            }
            cout << cts << "\n";
        } else if (cmd == "ca") {
            if (name == "..") {
                if (current->parent != nullptr) current = current->parent;
            } else if (name == "/") {
                current = album;
            } else {
                if (current->album.count(name)) current = current->album[name];
            }
            
            cout << current->value << "\n";
        }
    }
    
    return 0;
}