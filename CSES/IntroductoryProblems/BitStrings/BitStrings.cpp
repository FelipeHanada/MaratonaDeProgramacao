#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int MOD = (1e9+7);

int main() {
    int n;
    cin >> n;

    ll ans = 1;
    ll i = 2;  // 2^1
    for (; n; n >>= 1) {
        //  compute 2^n
        if (n & 1)
            ans = (ans * i) % MOD;
        i = (i * i) % MOD;
    }

    cout << ans << "\n";
}