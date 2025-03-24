#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 100;
constexpr int MAX_X = 1e6;
int dp[MAX_X + 1];

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i=0; i<n; i++)
        cin >> c[i];
    sort(c.begin(), c.end());
    while (c.back() > x) {
        n--;
        c.pop_back();
    }

    for (int i=0; i<n; i++) {
        // dp[i] = the maximum ways to sum i using at most the i'th coin
        dp[c[i]]++;
        for (int xi=c[i] + 1; xi<=x; xi++) {
            dp[xi] = (dp[xi] + dp[xi - c[i]]) % MOD;
        }
    }

    cout << dp[x] << "\n";
}
