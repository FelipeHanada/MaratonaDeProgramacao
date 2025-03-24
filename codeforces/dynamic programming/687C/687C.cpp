#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 500;
constexpr int MAX_K = 500;

bool dp[MAX_K + 1][MAX_K + 1];
int c[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> c[i];

    for (int i=0; i<=k; i++)
        fill_n(dp[i], k + 1, false);
    dp[0][0] = true;

    for (int i=0; i<n; i++) {
        for (int j=k; j>=c[i]; j--) {
            for (int a=0; a<=k; a++) {
                dp[j][a] = dp[j][a] || dp[j - c[i]][a] || (a - c[i] >= 0 && dp[j - c[i]][0, a - c[i]]);
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<=k; i++) {
        if (dp[k][i]) ans++;
    }
    cout << ans << "\n";
    for (int i=0; i<=k; i++) {
        if (dp[k][i]) cout << i << " ";
    }
    cout << "\n";
}
