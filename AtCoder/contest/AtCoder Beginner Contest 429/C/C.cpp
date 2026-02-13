#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n;
    cin >> n;

    unordered_map<int, ll> s;
    int x;
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> x;
        s[x]++;
    }

    for (auto [x, c] : s) {
        ans += (n - s[x]) * s[x] * (s[x] - 1) / 2;
        // we can pair this element with any other non-x
        //      with another element x
    }

    cout << ans << '\n';
}
