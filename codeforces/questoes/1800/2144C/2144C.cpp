#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n, y;
        cin >> n >> y;
        vector<int> a(n);
        int big = INT32_MIN;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            big = max(big, a[i]);
        }
        
        vector<int> cnt(big+1, 0);
        for (int i=0; i<n; i++) cnt[a[i]]++;

        vector<int> prefix(big+1);
        prefix[0] = 0;
        for (int i=1; i<=big; i++) {
            prefix[i] = prefix[i-1] + cnt[i];
        }

        ll ans = INT64_MIN;
        for (int x = 2; x <= max(2, big); x++) {
            ll curr = 0;
            for (int p = 1; (p-1) * x <= big; p++) {
                ll q = prefix[min(p * x, big)] - prefix[(p-1) * x];

                curr += q * p;
                curr -= max(0LL, q - cnt[p]) * y;
            }

            ans = max(ans, curr);
        }

        cout << ans << '\n';
    }
}

/*
the biggest x that we need to check is max A

for some x, we all the values of a[i]/x will fall under max A / x
    we can check the ranges of price that falls under all the possible prices
    this is enough to compute the total price for that x

the complexity is bounded by the sum of a harmonic series
    O(nlogn)

*/