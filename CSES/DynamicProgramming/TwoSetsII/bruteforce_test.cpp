#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9 + 7;

int solve(int n, int k, int curr_sum, int i) {
    if (curr_sum == k) return 1;
    if (curr_sum > k || i == n) return 0;

    int ans = 0;
    for (int j=i + 1; j <= n; j++) {
        ans = (ans + solve(n, k, curr_sum + j, j)) % MOD;
    }
    return ans;
}


int main() {
    int n; cin >> n;
    
    if (n % 4 == 1 || n % 4 == 2) {
        cout << 0 << "\n";
    }

    int k = (n + n * n) / 4;
    
    cout << solve(n, k, 0, 0) / 2 << "\n";
}
