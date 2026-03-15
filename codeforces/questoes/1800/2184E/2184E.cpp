#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct DSU {
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.assign(n, -1);
        size.assign(n, 1);
    }
    int find(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    void merge(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return;
        if (size[pi] < size[pj]) swap(pi, pj);
        parent[pj] = pi;
        size[pi] += size[pj];
    }
};

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        map<int, vector<int>> m;
        for (int i=0; i<n-1; i++)
            m[abs(a[i]-a[i+1])].push_back(i);


        DSU dsu(n);
        ll curr = 0;
        stack<ll> ans;
        for (int i=n-1; i>=1; i--) {
            // junta caminhos
            for (auto x : m[i]) {
                ll l = dsu.size[dsu.find(x)];
                ll r = dsu.size[dsu.find(x+1)];
                curr -= l*(l-1)/2;
                curr -= r*(r-1)/2;
                curr += (l+r)*(l+r-1)/2;
                dsu.merge(x, x+1);
            }
            ans.push(curr);
        }

        while (!ans.empty()) {
            cout << ans.top() << ' ';
            ans.pop();
        }
        cout << '\n';
    }
}

/*
3
5
5 1 4 2 3
    b[] = 4 3 2 1
3
3 2 1
    b[] = 1 1
4
3 1 2 4
    b[] = 2 1 2
*/
