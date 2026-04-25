#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int main() { _
    int n;
    cin >> n;
    vector<array<int,2>> a;
    vector<vector<int>> adj(n);
    for (int tt=0; tt<n; tt++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            for (int i=0; i<a.size(); i++) {
                if ((a[i][0] < x && x < a[i][1]) || (a[i][0] < y && y < a[i][1])) adj[a.size()].push_back(i);
                if ((x < a[i][0] && a[i][0] < y) || (x < a[i][1] && a[i][1] < y)) adj[i].push_back(a.size());
            }
            a.push_back((array<int,2>){x, y});
        } else {
            x--; y--;
            stack<int> stk; stk.push(x);
            vector<bool> seen(n, 0); seen[x] = 1;
            while (!stk.empty()) {
                auto curr = stk.top(); stk.pop();
                for (int neighbor : adj[curr]) if (!seen[neighbor]) {
                    seen[neighbor] = 1;
                    stk.push(neighbor);
                }
            }

            cout << (seen[y] ? "YES" : "NO") << '\n';
        }
    }
}
