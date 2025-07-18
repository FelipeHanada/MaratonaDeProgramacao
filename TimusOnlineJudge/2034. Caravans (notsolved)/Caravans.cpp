#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n, set<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[a].emplace(b);
        adj[b].emplace(a);
    }

    int s, f, r;
    cin >> s >> f >> r;

    
}
