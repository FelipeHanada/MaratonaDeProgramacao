#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int ans = 1;
    int prefix = a;
    while (b) {
        if (b & 1)
            ans = ((ll)ans * prefix) % MOD;
        
        b >>= 1;
        prefix = ((ll)prefix * prefix) % MOD;
    }

    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];

    vector<int> phi;
    for (int i=0; i<=n; i++) phi.push_back(i);
    for (int i=2; i<=n; i++) {
        if (phi[i] < i) continue;
        for (int j=i; j<=n; j += i)
            phi[j] -= phi[j] / i;
    }

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int x; cin >> x;

        int ans = 0;
        for (auto vi : v) {
            if (binexp(x, phi[vi]) % vi == 1 || x == 1 || vi == 1) {
                ans = (ans + 1) % MOD;
            }
        }

        cout << (1 << ans) << '\n';
    }
}