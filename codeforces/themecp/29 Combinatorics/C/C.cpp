#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(k, vector<int>(n));
        for (int i=0; i<k; i++) for (int j=0; j<n; j++) {
            cin >> a[i][j]; a[i][j]--;
        }

        vector<set<int>> adj(n);
        for (int i=0; i<k; i++) {
            for (int j=1; j<n-1; j++) {
                adj[a[i][j]].insert(a[i][j+1]);
            }
        }

        bool ok = 1;
        vector<bool> seen(n, 0);
        vector<bool> in_stack(n, 0);
        stack<pair<int,int>> dfs;
        for (int i=0; i<n && ok; i++) if (!seen[i]) {
            dfs.push({ i, 1 });
            
            while (!dfs.empty() && ok) {
                auto [ curr, state ] = dfs.top(); dfs.pop();

                if (state) {
                    if (seen[curr]) continue;
                    seen[curr] = 1;

                    dfs.push({ curr, 0 });
                    in_stack[curr] = 1;
                    for (int neighbor : adj[curr]) {
                        if (in_stack[neighbor]) {
                            ok = 0;
                            break;
                        }

                        if (seen[neighbor]) continue;
                        dfs.push({ neighbor, 1 });
                    }
                } else {
                    in_stack[curr] = 0;
                }
            }
        }


        cout << (ok ? "YES" : "NO") << '\n';
    }
}
