#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    ll n, m, c;
    cin >> n >> m >> c;

    map<ll, int> s;
    ll x;
    for (int i=0; i<n; i++) {
        cin >> x;
        if (x == 0) x = m;
        s[x]++;
        s[x + m]++;
    }

    vector<ll> prefix_p;
    vector<int> prefix_s;
    prefix_p.push_back(0);
    prefix_s.push_back(0);
    for (auto [x, cnt] : s) {
        prefix_p.push_back(x);
        prefix_s.push_back(prefix_s.back() + cnt);
    }

    ll ans = 0;
    for (int i=0; prefix_p[i]<m; i++) {
        auto lb = lower_bound(prefix_s.begin(), prefix_s.end(), c + prefix_s[i]);
        ans += (min(m, prefix_p[i+1]) - prefix_p[i]) * (*lb - prefix_s[i]);
    }

    cout << ans << '\n';

    // vector<ll> prefix(2*m+1, 0);
    // for (auto [x, cnt] : s) {
    //     prefix[x] += cnt;
    //     prefix[m + x] += cnt;
    // }
    // for (int i=1; i<2*m+1; i++) {
    //     prefix[i] += prefix[i-1];
    // }

    // ll ans = 0;
    // for (int i=0; i<m; i++) {
    //     // prefix[r] - prefix[i] = smallest bigger than c
    //     auto lb = lower_bound(prefix.begin(), prefix.end(), c + prefix[i]);
    //     ans += *lb - prefix[i];
    // }

    // cout << ans << '\n';
}
