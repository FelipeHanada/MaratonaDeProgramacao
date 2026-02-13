#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> req(n+1);
    req[0] = {0, 0};
    for (int i=1; i<=n; i++) {
        cin >> req[i].first >> req[i].second;
    }
    sort(req.begin(), req.end());

    int ans = 0;
    for (int i=0; i<n; i++) {
        // how many points can we get from minute req[i] to req[i+1]
        int time = req[i+1].first - req[i].first;

        if (req[i].second == req[i+1].second) {
            // the bigger even number at most equal to time
            ans += time ^ (time & 1);
        } else {
            // the bigger odd number at most equal to time
            if (time % 2) ans += time;
            else ans += time - 1;
        }
    }
    // plus the remaining time
    ans += m - req[n].first;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}