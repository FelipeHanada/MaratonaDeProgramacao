#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


constexpr int N = int(1e6)+5;
int sieve[N];

int main() { _
    fill_n(sieve, N, 0);
    for (int i=2; i<N; i++) if (!sieve[i]) {
        for (int j=i; j<N; j+=i) if (!sieve[j]) {
            sieve[j] = i;
        }
    }

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;

        map<int, int> decomp;
        while (n > 1) {
            decomp[sieve[n]]++;
            n /= sieve[n];
        }

        int ans = 0;
        ans += decomp.size();
        int x = 0;
        for (auto [p, pow] : decomp) x += pow;
        ans += x - 1;
        cout << ans << '\n';
    }
}

/*

*/