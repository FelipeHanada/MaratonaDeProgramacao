#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> parent;
    vector<int> rank;
    DSU(int n) {
        parent.assign(n, -1);
        rank.assign(n, 0);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    bool merge_set(int i, int j) {
        int pi = find(i),
            pj = find(j);
        if (pi == pj) return 0;
        if (rank[pi] < rank[pj]) swap(pi, pj);
        parent[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
        return 1;
    }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int max_a = INT32_MIN;
    for (int i=0; i<n; i++) max_a = max(max_a, a[i]);

    vector<vector<int>> divs(max_a+1);
    for (int i=1; i<divs.size(); i++) { // O(max_a log max_a) porque segue uma série harmonica
        for (int j=i; j<divs.size(); j+=i) {
            divs[j].push_back(i);
        }
    }
    // max_a + max_a/2 + max_a/3 + max_a/4 + ... + max_a/max_a
    // max_a * (1/1 + 1/2 + 1/3 + ... + 1/max_a)
    // O(max_a * log max_a)

    vector<vector<int>> cands(max_a+1, vector<int>());
    for (int i=0; i<n; i++) {
        for (int div : divs[a[i]]) { // O(quantidade de divisores)
            cands[div].push_back(i);
        }
    }

    DSU dsu(n);
    ll ans = 0;
    for (int g=max_a; g>0; g--) {
        vector<int>& v = cands[g];

        for (int i=0; i<int(v.size())-1; i++) {
            if (dsu.merge_set(v[i], v[i+1])) {
                ans += g;
            }
        }
    }

    cout << ans << '\n';
}
