/*
# key idea

결국 splay_tree는 BBST이기에 중위 순서로 돌았을 때 1차원 배열이 됨.
-> 따라서 특정 노드의 위치가 중위 순회 기준으로 몇번째인지 알 수 있다면
   해당 노드의 인덱스 번호를 알 수 있음.
   
이걸 어떻게 찾느냐?
-> 각 노드가 자식 노드가 몇개가 있는지 저장하는 정보인 count가 존재.
   해당 count을 이용하여 자신의 위치를 탐색.

   1. splay를 통해서 원하는 노드를 루트로 올림
   2. 이때 left 자식의 count가 원하는 노드의 index가 됨.
   
   이때 중요한 사항은 splay에서 push를 통해서 lazy를 수행해줘야함.
*/

#include <iostream>
#include <vector>
#include <algorithm>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#endif

using namespace std;

using i64 = long long;

template <typename T>
struct node {
    using node_ptr = node*;
    
    node_ptr left, right, parent;
    
    T key; i64 value; bool flip = false;
    
    int count = 0;
};

template <typename T>
struct splay_tree {
    using node_ptr = node<T>*;
    
    node_ptr root = nullptr;
    
    void push(node_ptr nd) {
        if (!nd->flip) return;
        
        swap(nd->left, nd->right);
        
        if (nd->left != nullptr) nd->left->flip ^= true;
        if (nd->right != nullptr) nd->right->flip ^= true;
        
        nd->flip = false;
    }

    void update(node_ptr nd) {
        nd->count = 1;
        
        if (nd->left != nullptr) {
            push(nd->left);
            nd->count += nd->left->count;
        }
        if (nd->right != nullptr) {
            push(nd->right);
            nd->count += nd->right->count;
        }
    }

    void rotate(node_ptr nd) {
        node_ptr p = nd->parent, ptr = nullptr;
        
        push(p);
        push(nd);
        
        if (p == nullptr) return;
        
        if (nd == p->left) {
            p->left = ptr = nd->right;
            nd->right = p;
        } else {
            p->right = ptr = nd->left;
            nd->left = p;
        }
        
        nd->parent = p->parent;
        p->parent = nd;
        
        if (ptr != nullptr) ptr->parent = p;
        
        if (nd->parent == nullptr)
            root = nd;
        else if (nd->parent->left == p)
            nd->parent->left = nd;
        else
            nd->parent->right = nd;
        
        update(p); update(nd);
    }
    
    void splay(node_ptr nd, node_ptr gp = nullptr) {
        push(nd);
        
        while (nd->parent != gp) {
            node_ptr p = nd->parent;
            
            if (p->parent == gp) {
                rotate(nd); break;
            }
            
            node_ptr g = p->parent;
            
            if (g != nullptr) {
                if ((g->left == p) ^ (p->left == nd)) rotate(nd);
                else rotate(p);
            }
            rotate(nd);
        }
        
        if (gp == nullptr) root = nd;
    }
    
    void splay_order(int k) {
        node_ptr nd = root;
        
        push(nd);
        while (true) {
            while (nd->left != nullptr && nd->left->count > k) {
                nd = nd->left;
                push(nd);
            }
            
            if (nd->left != nullptr) k -= nd->left->count;
            if (k == 0) break; k--;
            
            nd = nd->right;
            push(nd);
        }
        
        splay(nd);
    }
    
    bool find(const T& key) {
        node_ptr p = root;
        
        if (p == nullptr) return false;
        
        while (p != nullptr) {
            if (key == p->key) break;
            
            node_ptr ptr = (key < p->key ? p->left : p->right);
            if (ptr == nullptr) break;
            p = ptr;
        }
        
        splay(p);
        return key == p->key;
    }
    
    node_ptr insert(const T& key, i64 value) {
        using node = node<T>;
        
        node_ptr p = root;
        node_ptr* ptr = nullptr;
        
        if (p == nullptr) {
            root = new node { nullptr, nullptr, nullptr, key, value };
            return root;
        }
        
        while (true) {
            node_ptr& nd = (key < p->key ? p->left : p->right);
            
            if (nd == nullptr) { ptr = &nd; break; }
            p = nd;
        }
        
        *ptr = new node { nullptr, nullptr, p, key, value };
        
        splay(*ptr);
        
        return root;
    }
    
    void erase(const T& key) {
        if (!find(key)) return;
        
        node_ptr p = root;
        
        if (p->left != nullptr && p->right != nullptr) {
            root = p->left; root->parent = nullptr;
            
            node_ptr nd = root;
            
            while (nd->right != nullptr) nd = nd->right;
            
            nd->right = p->right; p->right->parent = nd;
        } else if (p->left != nullptr) {
            root = p->left;
            root->parent = nullptr;
        } else if (p->right != nullptr) {
            root = p->right;
            root->parent = nullptr;
        } else root = nullptr;
        
        delete p;
    }
    
    T find_by_order(int k) {
        splay_order(k);
        
        return root->key;
    }
    
    node_ptr gather(int start, int end) {
        splay_order(end + 1);
        
        node_ptr ptr = root;
        
        splay_order(start - 1);
        
        splay(ptr, root);
        
        return root->right->left;
    }
    
    void flip(int start, int end) {
        node_ptr nd = gather(start, end);
        
        nd->flip ^= true;
    }
    
    int find_index(node_ptr nd) {
        splay(nd);
        
        push(nd);
        
        int cnt = 0;
        if (nd->left != nullptr) cnt += nd->left->count;
        
        return cnt;
    }
};

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n;
    
    while (cin >> n, n) {
        splay_tree<int> tree;
        
        tree.insert(-1, 0); tree.insert(n, 0);
        
        vector<splay_tree<int>::node_ptr> nodes;
        
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            
            nodes.push_back(tree.insert(i, x));
        }
        
        sort(nodes.begin(), nodes.end(), [] (splay_tree<int>::node_ptr a, splay_tree<int>::node_ptr b) {
            if (a->value == b->value)
                return a->key < b->key;
            return a->value < b->value;
        });
        
        for (int i = 0; i < nodes.size(); i++) {
            int idx = tree.find_index(nodes[i]);
            cout << idx << " ";
            tree.flip(i + 1, idx);
        }
        
        cout << "\n";
    }
}