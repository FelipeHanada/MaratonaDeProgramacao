#include <bits/stdc++.h>
using namespace std;


struct tree {
    int id;
    vector<tree*> children;
    void add_child(tree* t) {
        children.push_back(t);
    };
    void calc_n_descendents(vector<int> &v) {
        v[id] = 0;
        for (auto child : children) {
            child->calc_n_descendents(v);
            v[id] += 1 + v[child->id];
        }
    }
};

int main() {
    int n; cin >> n;
    vector<tree> t;
    for (int i=0; i<n; i++) {
        t.push_back({i, {}});
    }
    
    for (int i=1; i<n; i++) {
        int boss; cin >> boss;
        t[boss-1].add_child(&(t[i]));
    }

    vector<int> v(n);
    t[0].calc_n_descendents(v);

    for (int i=0; i<n; i++) {
        cout << v[i] << " ";
    } cout << endl;
}