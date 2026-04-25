#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    deque<ll> b(n);
    for (int i=0; i<n; i++) {
        b[i] = a[i] % k;
    }
    sort(b.begin(), b.end());

    ll ans = INT32_MAX;

    for (int i=0; i<n; i++) {
        ans = min(ans, min(ans, b.back() - b.front()));
        b.push_back(b.front() + k);
        b.pop_front();
    }

    cout << ans << '\n';
}
