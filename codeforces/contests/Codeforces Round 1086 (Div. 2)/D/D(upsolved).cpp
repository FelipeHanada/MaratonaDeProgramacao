#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<bool>> m(n, vector<bool>(n));
    for (int i=0; i<n; i++) {
        cin >> s[i];
        for (int j=0; j<n; j++) {
            m[i][j] = s[i][j] == '1';
        }
    }

    for (int i=0; i<n; i++) {
        if (!m[i][i]) {
            cout << "NO\n";
            return;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (m[i][j] && m[j][i]) {
                cout << "NO\n";
                return;
            }
        }
    }

    vector<set<int>> adj(n);
    vector<set<int>> adjd(n);
    vector<pair<int,int>> edges;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (j != i && m[i][j]) {
            bool add = 1;
            for (int k=0; k<n; k++) if (k != i && k != j && m[i][k] && m[k][j]) {
                add = 0;
            }

            if (add) {
                adj[i].insert(j);
                adj[j].insert(i);
                adjd[i].insert(j);
                edges.push_back({i, j});
            }
        }
    }

    if (edges.size() != n-1) {
        cout << "NO\n";
        return;
    }

    stack<int> stk; stk.push(0);
    vector<bool> seen(n, 0); seen[0] = 1;
    while (!stk.empty()) {
        auto curr = stk.top(); stk.pop();

        for (int neighbor : adj[curr]) {
            if (seen[neighbor]) continue;
            seen[neighbor] = 1;
            stk.push(neighbor);
        }
    }

    if (count(seen.begin(), seen.end(), false)) {
        cout << "NO\n";
        return;
    }

    vector<vector<bool>> m2(n, vector<bool>(n, 0));
    for (int i=0; i<n; i++) {
        stack<int> stk; stk.push(i);
        m2[i][i] = 1;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();

            for (int neighbor : adjd[curr]) {
                if (m2[i][neighbor]) continue;
                m2[i][neighbor] = 1;
                stk.push(neighbor);
            }
        }
    }

    bool ok = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (m[i][j] != m2[i][j]) ok = 0;
        }
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto [x, y] : edges) {
        cout << x+1 << ' ' << y+1 << '\n';
    }
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
}