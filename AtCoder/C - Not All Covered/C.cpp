#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> diff(n+1);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        diff[x]++;
        diff[y]--;
    }

    for (int i=1; i<=n; i++) diff[i] += diff[i-1];

    int ans = INT32_MAX;
    for (int i=0; i<n; i++) {
        ans = min(ans, diff[i]);
    }

    cout << ans << '\n';
}
