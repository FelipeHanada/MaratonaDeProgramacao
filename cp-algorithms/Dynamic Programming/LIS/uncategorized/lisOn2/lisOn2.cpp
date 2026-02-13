#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int v[n], dp[n];
    for (int i=0; i<n; i++) {
        cin >> v[i];
        int p = 0;
        for (int j=0; j<i; j++) {
            if (v[i] <= v[j]) continue;
            p = max(p, dp[j]);
        }
        dp[i] = p + 1;
    }

    int lis = 0;
    for (int i=0; i<n; i++) {
        lis = max(lis, dp[i]);
        cout << dp[i] << ' ';
    }
    cout << '\n';
    cout << lis << '\n';
}
