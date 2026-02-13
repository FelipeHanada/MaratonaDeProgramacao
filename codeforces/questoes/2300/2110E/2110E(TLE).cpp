#include <bits/stdc++.h>
using namespace std;


#define _1 first
#define _2 second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    map<pair<int, int>, vector<int>> a_inv;
    set<int> v, p;
    for (int i=0; i<n; i++) {
        cin >> a[i]._1 >> a[i]._2;
        v.insert(a[i]._1);
        p.insert(a[i]._2);
        a_inv[a[i]].push_back(i);
    }
    map<int, int> vcomp, pcomp;
    vector<int> comp_inv;
    {
        int i=0;
        for (int x : v) {
            vcomp[x] = i++;
            comp_inv.push_back(x);
        }
        for (int x : p) {
            pcomp[x] = i++;
            comp_inv.push_back(x);
        }
    }

    vector<unordered_multiset<int>> adj(v.size() + p.size());
    for (auto &[av, ap] : a) {
        adj[vcomp[av]].insert(pcomp[ap]);
        adj[pcomp[ap]].insert(vcomp[av]);
    }

    int start = -1, end = -1;
    for (int i=0; i<v.size() + p.size(); i++) {
        if (adj[i].size() & 1) {
            if (start == -1) start = i;
            else if (end == -1) end = i;
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    if (start != -1) {
        adj[start].insert(end);
        adj[end].insert(start);
    } else {
        start = 0;
    }

    vector<int> circuit;
    stack<int> stk;
    stk.push(start);
    while (!stk.empty()) {
        auto curr = stk.top();
        if (adj[curr].empty()) {
            circuit.push_back(curr);
            stk.pop();
        } else {
            auto next = *adj[curr].begin();
            adj[curr].extract(next);
            adj[next].extract(curr);
            stk.push(next);
        }
    }

    circuit.pop_back();
    if (circuit.size() + (end != -1 ? -1 : 0) < n) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int i=0;
    if (end != -1) {
        while (circuit[i] != start || circuit[(i+1)%circuit.size()] != end) {
            i = (i+1)%circuit.size();
        }
    }

    for (int j=i; (j-1+circuit.size())%circuit.size()!=i; j=(j-1+circuit.size())%circuit.size()) {
        pair<int, int> sound;
        if (circuit[j] < v.size()) {
            sound = {comp_inv[circuit[j]], comp_inv[circuit[(j-1+circuit.size())%circuit.size()]]};
        } else {
            sound = {comp_inv[circuit[(j-1+circuit.size())%circuit.size()]], comp_inv[circuit[j]]};
        }

        cout << a_inv[sound].back() + 1 << ' ';
        a_inv[sound].pop_back();
    }

    if (end == -1) {
        cout << a_inv[{comp_inv[circuit[0]], comp_inv[circuit[1]]}].back() + 1 << ' ';
    }

    cout << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}