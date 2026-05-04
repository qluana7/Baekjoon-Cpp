#include <iostream>
#include <vector>
#include <algorithm>

#define All(c) c.begin(), c.end()
#define Range(It, name) It name##_begin, It name##_end

using namespace std;

template <typename Iter>
void order(Range(Iter, in), Range(Iter, post)) {
    if (in_begin + 1 == in_end) 
    { cout << *in_begin << " "; return; }

    int root = post_end[-1];

    cout << root << " ";

    auto it = find(in_begin, in_end, root);
    int s1 = distance(in_begin, it), s2 = distance(it + 1, in_end);

    if (s1 > 0) order(in_begin, it, post_begin, post_begin + s1);

    if (s2 > 0) order(it + 1, in_end, post_end - s2 - 1, post_end - 1);
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> in(n), post(n);
    for (auto& x : in) cin >> x;
    for (auto& x : post) cin >> x;
    
    order(All(in), All(post));
}