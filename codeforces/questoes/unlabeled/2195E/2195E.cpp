#include <bits/stdc++.h>
using namespace std;


constexpr int md = int(1e9) + 7;
int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> parent(n + 1, -1);
        vector<vector<int>> child(n + 1);
        parent[1] = -1;
        vector<int> deg(n+1, 0);
        queue<int> q;
        for (int i=1; i<=n; i++) {
            int a, b;
            cin >> a >> b;
            if (a) {
                deg[i]++;
                parent[a] = i;
                child[i].push_back(a);
            }
            if (b) {
                deg[i]++;
                parent[b] = i;
                child[i].push_back(b);
            }
            if (deg[i] == 0) q.push(i);
        }

        vector<int> dp(n+1, 0);
        stack<int> stk;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            stk.push(curr);

            if (parent[curr] == -1) continue;
            dp[parent[curr]] = add(dp[parent[curr]], add(dp[curr], 2));
            if (--deg[parent[curr]] == 0) {
                q.push(parent[curr]);
            }
        }

        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();

            dp[curr] = add(dp[curr], 1);
            for (int c : child[curr]) {
                dp[c] = add(dp[c], dp[curr]);
            }
        }

        for (int i=1; i<=n; i++) {
            cout << dp[i] << ' ';
        }
        cout << '\n';
    }
}