#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define _1 first
#define _2 second
#define ll long long

void precompute() {

}

struct DSU {
    vector<int> p;
    vector<int> rank;
    DSU(int n) {
        p.assign(n, -1);
        rank.assign(n, 1);
    }
    int find(int i) {
        int curr_i = i;
        while (p[curr_i] != -1) curr_i = p[curr_i];
        if (i != curr_i) p[i] = curr_i;
        return curr_i;
    }
    bool set_union(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return false;
        if (rank[pi] < rank[j]) swap(pi, pj);
        p[pj] = pi;
        if (rank[pi] == rank[pj]) rank[pi]++;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    vector<int> prefix(n), suffix(n);
    prefix.front() = p.front();
    suffix.back() = p.back();
    for (int i=1; i<n; i++) {
        prefix[i] = min(prefix[i-1], p[i]);
        suffix[n-i-1] = max(suffix[n-i], p[n-i-1]);
    }

    DSU dsu(n+1);
    vector<pair<int, int>> ans;
    pair<int, int> lastps = {-1, -1};
    for (int i=1; i<n; i++) {
        if (prefix[i-1] > suffix[i]) {
            cout << "No\n";
            return;
        }
        if (dsu.set_union(prefix[i-1], suffix[i]))
            ans.push_back({prefix[i-1], suffix[i]});
        if (dsu.set_union(p[i], suffix[i]))
            ans.push_back({p[i], suffix[i]});
    }

    cout << "Yes\n";
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}


int main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
