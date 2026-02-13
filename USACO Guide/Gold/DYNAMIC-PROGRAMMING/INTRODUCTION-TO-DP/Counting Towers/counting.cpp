#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MOD = 1e9+7;
constexpr int MAX_N = 1e6;
int t, n;

int count1[MAX_N+1]; // count splitted towers
int count2[MAX_N+1]; // count jointed towers
int sum1;
int sum2;

void precompute() {
    count1[0] = count1[1] = 1;
    count2[0] = 1; count2[1] = 1;

    for (int i=2; i<=MAX_N; i++) {
        count1[i] = (((ll)count1[i-1] * 4) % MOD + count2[i-1]) % MOD;
        // we can:
        // 1. prolong both columns in a splitted tower
        // 2-3. add a 1x1 brick and prolong just one of the columns of a splitted tower
        // 4. add two 1x1 bricks on top of a splitted tower
        // 5. add two 1x1 bricks on top of a jointed tower

        count2[i] = (((ll)count2[i-1] * 2) % MOD + count1[i-1]) % MOD;
        // we can:
        // 1. prolong a jointed tower
        // 2. add a 1x2 brick in a jointed tower
        // 3. add a 1x2 brick in a splitted tower
    }
}

void solve() {
    cin >> n;
    cout << (count1[n] + count2[n]) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    cin >> t;
    while (t--) {
        solve();
    }
}
