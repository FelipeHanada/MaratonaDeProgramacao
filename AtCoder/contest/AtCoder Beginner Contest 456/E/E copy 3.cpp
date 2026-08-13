#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(0);

int n, m, w;
vector<vector<int>> adj;
vector<string> h(n);

vector<bool> seen;
vector<bool> instk;
bool dfs(int i) {
    seen[i] = 1;
    instk[i] = 1;

    queue<int> q;
    q.push(i);
    for (int j=0; j<w-1; j++) {
        queue<int> next;

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            if (h[curr][j+1] == 'o') next.push(curr);
            for (int neighbor : adj[curr]) if (h[neighbor][j+1] == 'o') {
                next.push(neighbor);
            }
        }

        swap(q, next);
    }

    {
        queue<int> next;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            if (h[curr][0] == 'o') next.push(curr);
            for (int neighbor : adj[curr]) if (h[neighbor][0] == 'o') {
                next.push(neighbor);
            }
        }
        swap(q, next);
    }


    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        if (instk[curr]) return 1;
        if (seen[curr]) continue;
        else {
            bool ans = dfs(curr);
            if (ans) return ans;
        }
    }

    instk[i] = 0;
    return 0;
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cin >> w;
    h.resize(n);
    for (int i=0; i<n; i++) cin >> h[i];



    seen.assign(n, 0);
    instk.assign(n, 0);
    bool ok = 0;
    for (int i=0; !ok && i<n; i++) if (!seen[i]) {
        ok = dfs(i);
    }

    cout << (ok ? "Yes" : "No") << '\n';
}


int main() { _
    int tt;
    cin >> tt;
    while (tt--) solve();
}
