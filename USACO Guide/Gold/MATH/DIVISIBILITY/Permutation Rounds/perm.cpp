#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int md = int(1e9) + 7;

int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ((ll)ans * a) % md;
        a = ((ll)a * a) % md;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n; cin >> n;

    vector<int> sieve(n, 0);
    for (int i=2; i<=n; i++) if (!sieve[i]) {
        for (int j = i; j <= n; j += i) if (!sieve[j]) {
            sieve[j] = i;
        }
    }

    vector<int> perm(n);
    for (int i=0; i<n; i++) {
        cin >> perm[i];
        perm[i]--;
    }

    vector<bool> seen(n, 0);
    map<int, int> big;
    for (int i=0; i<n; i++) if (!seen[i]) {
        int size = 0;
        for (int j = i; !seen[j]; j = perm[j]) {
            seen[j] = 1;
            size++;
        }

        map<int, int> curr;
        while (size > 1) {
            curr[sieve[size]]++;
            size /= sieve[size];
        }

        for (auto [p, cnt] : curr) {
            big[p] = max(big[p], cnt);
        }
    }

    int ans = 1;
    for (auto [p, cnt] : big) {
        ans = ((ll)ans * binpow(p, cnt)) % md;
    }
    cout << ans << '\n';
}
