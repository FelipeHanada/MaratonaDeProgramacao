#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int n, m; cin >> n >> m;
    vector<int> ans(m, -1);
    for (int i=0; i<n; i++) {
        int c, s; cin >> c >> s;
        ans[c-1] = max(ans[c-1], s);
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
