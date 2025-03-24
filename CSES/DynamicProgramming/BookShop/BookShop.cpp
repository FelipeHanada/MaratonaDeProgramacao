#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1000;
constexpr int MAX_X = 1e5;
int c[MAX_N];
int p[MAX_N];
int dp[MAX_X + 1];

int main() {
    int n, x;
    cin >> n >> x;

    for (int i=0; i<n; i++)
        cin >> c[i];
    for (int i=0; i<n; i++)
        cin >> p[i];

    fill_n(dp, x + 1, 0);
    for (int i=0; i<n; i++) {
        for (int j=x; j>=c[i]; j--) {
            dp[j] = max(dp[j], p[i] + dp[j - c[i]]);
        }
    }

    cout << dp[x] << "\n";
}