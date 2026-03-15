#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<vector<int>> desired;
    {
        vector<bool> seen(n, 0);
        for (int i=0; i<n; i++) if (!seen[i]) {
            vector<int> comp;
            int curr = i;
            while (!seen[curr]) {
                seen[curr] = 1;
                comp.push_back(curr);
                curr = p[curr];
            }
            desired.push_back(comp);
        }
    }

    vector<vector<array<int,2>>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    auto check = [&](int W) -> bool {
        vector<int> comps(n, -1);
        for (int i=0; i<n; i++) if (comps[i] == -1) {
            stack<int> stk; stk.push(i);
            comps[i] = i;

            while (!stk.empty()) {
                auto curr = stk.top(); stk.pop();
                for (auto [ y, w ] : adj[curr]) if (w >= W) {
                    if (comps[y] != -1) continue;
                    comps[y] = i;
                    stk.push(y);
                }
            }
        }

        for (auto comp : desired) {
            for (int i=0; i<comp.size()-1; i++) {
                if (comps[comp[i]] != comps[comp[i+1]]) return 0;
            }
        }

        return 1;
    };


    int l = 0, r = int(1e9)+5;
    if (check(r)) { // nao precisou fazer nenhuma troca
        cout << "-1\n";
        return 0;
    }

    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << '\n';
}
