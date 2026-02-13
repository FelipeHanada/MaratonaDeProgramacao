#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define f first
#define s second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, ll> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    vector<pair<int, ll>> a(m.begin(), m.end());

    vector<ll> dp(m.size()+1);
    dp[0] = 0;
    dp[1] = a[0].f * a[0].s;
    for (int i=2; i<=a.size(); i++) {
        dp[i] = max(dp[i-1], max(
            (a[i-2].f < a[i-1].f - 1 ? dp[i-1] + a[i-1].f * a[i-1].s : 0),
            dp[i-2] + a[i-1].f * a[i-1].s
        ));
    }

    cout << dp[m.size()] << '\n';
}
