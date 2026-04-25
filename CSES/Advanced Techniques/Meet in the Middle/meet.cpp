#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> left(n/2), right(n-n/2);
    for (int i=0; i<n/2; i++) cin >> left[i];
    for (int i=0; i<n-n/2; i++) cin >> right[i];

    vector<ll> sums;
    for (int i=0; i<(1<<(n/2)); i++) {
        int mask = i;
        ll sum = 0;
        for (int j=0; mask; j++) if (mask & (1 << j)) {
            sum += left[j];
            mask &= ~(1<<j);
        }

        sums.push_back(sum);
    }

    sort(sums.begin(), sums.end());

    ll ans = 0;
    for (int i=0; i<(1<<(n-n/2)); i++) {
        int mask = i;
        ll sum = 0;
        for (int j=0; mask; j++) if (mask & (1 << j)) {
            sum += right[j];
            mask &= ~(1<<j);
        }

        auto lb = lower_bound(sums.begin(), sums.end(), x - sum);
        auto ub = upper_bound(sums.begin(), sums.end(), x - sum);
        ans += distance(lb, ub);
    }

    cout << ans << '\n';
}   