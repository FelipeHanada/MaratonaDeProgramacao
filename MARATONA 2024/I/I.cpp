#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = int(1e6);
constexpr int md = int(1e9)+7;
int mult(int a, int b) { return ((ll)a * b) % md; }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sieve(N+1, 0);
    for (int i=2; i<=N; i++) if (!sieve[i]) {
        for (int j=i; j<=N; j+=i) if (!sieve[j]) {
            sieve[j] = i;
        }
    }

    int n; cin >> n;
    vector<int> cnt(N+1, 0);
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    vector<int> f(N+1, 0);
    // f[i] = quantidade de comidas que a pessoa i é alérgica
    for (int i=2; i<=N; i++) {
        for (int j=i; j<=N; j+=i) {
            f[i] += cnt[j];
        }
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        vector<int> rad;
        while (x > 1) {
            if (rad.empty() || rad.back() != sieve[x]) rad.push_back(sieve[x]);
            x /= sieve[x];
        }

        int ans = 0;
        for (int mask = 0; mask < (1<<rad.size()); mask++) {
            // principio da inclusão-exclusão
            int k = 1;
            for (int i=0; i < rad.size(); i++) {
                if (mask & (1 << i)) k *= rad[i];
            }
            ans += (__builtin_popcount(mask) & 1 ? 1 : -1) * f[k];
        }

        cout << binpow(2, n - ans) << '\n';
    }
}
