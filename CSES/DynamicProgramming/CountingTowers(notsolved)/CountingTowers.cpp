#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e6;
int dp[MAX_N + 1][MAX_N + 1] = {0};

int main() {
    int t, n;
    cin >> t;

    for (int test=0; test<t; test++) {
        cin >> n;
        cout << dp[n][n] << "\n";
    }
}
