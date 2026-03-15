#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> parent(n);
        for (int i=0; i<n; i++) {
            cin >> parent[i];
            parent[i]--;
        }

        vector<int> sons(n, 0);
        for (int i=0; i<n; i++) {
            if (parent[i] != i) {
                sons[parent[i]]++;
            }
        }
        vector<int> leafs;
        for (int i=0; i<n; i++) if (sons[i] == 0) leafs.push_back(i);

        vector<bool> seen(n, 0);
        vector<vector<int>> paths;
        for (int leaf : leafs) {
            vector<int> path;
            while (!seen[leaf]) {
                seen[leaf] = 1;
                path.push_back(leaf);
                leaf = parent[leaf];
            }
            reverse(path.begin(), path.end());
            paths.push_back(path);
        }

        cout << paths.size() << '\n';
        for (vector<int>& path : paths) {
            cout << path.size() << '\n';
            for (int x : path) cout << x + 1 << ' ';
            cout << '\n';
        }
    }
}
