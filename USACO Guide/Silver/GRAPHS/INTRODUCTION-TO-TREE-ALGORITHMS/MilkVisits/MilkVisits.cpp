#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    int n, q; cin >> n >> q;

    bool seen[n];
    bool farms[n];
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        farms[i] = (c == 'H');
        seen[i] = false;
    }

    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int curr_component = 0;
    int components[n];
    for (int i=0; i<n; i++) {
        if (seen[i]) continue;
        seen[i] = true;

        stack<int> dfs; dfs.emplace(i);
        while (dfs.size() > 0) {
            int curr = dfs.top(); dfs.pop();
            components[curr] = curr_component;

            for (int x : adj[curr]) {
                if (seen[x] || (farms[curr] != farms[x])) continue;
                seen[x] = true;
                dfs.emplace(x);
            }
        }

        curr_component++;
    }

    for (int i=0; i<q; i++) {
        int a, b; char c;
        cin >> a >> b >> c;
        a--; b--;

        if (((c == 'H') ? farms[a] : !farms[a]) || (components[a] != components[b])) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}
