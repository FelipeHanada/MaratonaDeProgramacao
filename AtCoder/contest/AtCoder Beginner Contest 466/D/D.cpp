#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int n, m; cin >> n >> m;

    stack<pair<int,int>> stk;
    while (m--) {
        int r, c; cin >> r >> c;
        stk.push({ r, c });
    }

    int ans = 0;
    vector<bool> r(n, 0), c(n, 0);
    while (!stk.empty()) {
        auto [ x, y ] = stk.top(); stk.pop();

        if (!r[x] && !c[y]) ans++;
        r[x] = 1;
        c[y] = 1;
    }

    cout << ans << '\n';
}
