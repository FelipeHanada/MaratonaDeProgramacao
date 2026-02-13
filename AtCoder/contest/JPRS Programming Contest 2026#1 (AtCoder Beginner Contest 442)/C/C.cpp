#include <bits/stdc++.h>
using namespace std;


using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for (int i=0; i<n; i++) {
        int x = n - adj[i].size() - 1;
        cout << (ll)x * (x-1) * (x-2) / 6 << ' ';
    }
    cout << '\n';
}
