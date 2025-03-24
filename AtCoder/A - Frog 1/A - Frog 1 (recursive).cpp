#include <bits/stdc++.h>
using namespace std;


int n;
constexpr int MAXN = (int)1e5;
int h[MAXN];
int dp[MAXN];

int solve(int k) { // minimum cost to k'th stone
    if (dp[k] != -1) return dp[k];  // if it is already calculated, return
    return min(solve(k-1) + abs(h[k] - h[k-1]), solve(k-2) + abs(h[k] - h[k-2]));
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> h[i];

    fill_n(dp, n, -1);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    cout << solve(n - 1) << "\n";
}