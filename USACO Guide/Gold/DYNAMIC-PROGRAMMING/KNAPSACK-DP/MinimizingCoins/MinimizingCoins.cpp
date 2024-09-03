#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 100;
constexpr int MAX_X = 1e6;
int n, x;
int v[MAX_N];
int dp[MAX_X];
//  dp[i]: minimum number of coins to sum i + 1


int main() {
    cin >> n >> x;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    fill_n(dp, x, INT32_MAX);
    for (int i=0; i<n; i++) {
        dp[v[i] - 1] = 1;
    }
    for (int i=0; i<x; i++) {
        if (dp[i] == INT32_MAX) continue;
        
        for (int j=0; j<n; j++) {
            if (i + v[j] >= x) continue;
            dp[i + v[j]] = min(dp[i + v[j]], dp[i] + 1);
        }
    }

    cout << ((dp[x - 1] != INT32_MAX) ? dp[x - 1] : -1) << endl;
}