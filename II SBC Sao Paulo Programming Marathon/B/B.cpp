#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6);

int main() {
    int n, c, k;
    cin >> n >> c >> k;

    vector<int> a(N+1, 0);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    vector<ll> dp0(N+1), dp1(N+1);
    dp0[0] = 0; dp1[0] = INT64_MAX;

    for (int i=1; i<=N; i++) {
        if (a[i] == 1) dp0[i] = INT64_MAX;
        else {
            dp0[i] = INT64_MAX;
            if (dp0[i-1] != INT64_MAX) dp0[i] = min(dp0[i], dp0[i-1]);
            if (dp1[i-1] != INT64_MAX) dp0[i] = min(dp0[i], dp1[i-1]);
        }

        dp1[i] = INT64_MAX;
        if (dp0[i-1] != INT64_MAX) dp1[i] = min(dp1[i], dp0[i-1] + c + k);
        if (dp1[i-1] != INT64_MAX) dp1[i] = min(dp1[i], dp1[i-1] + c);
    }

    if (a[N] == 1) cout << dp1[N] << '\n';
    else cout << dp0[N] << '\n';
}