#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weight(n), value(n);
    for (int i=0; i<n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<ll> dp(w+1, 0);
    for (int i=0; i<n; i++) {
        for (int j=w; j>=weight[i]; j--) {
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }

    cout << dp[w] << '\n';
}
