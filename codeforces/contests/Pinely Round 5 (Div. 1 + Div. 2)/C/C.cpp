#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second


void solve() {
    int n, x;
    cin >> n >> x;
    deque<ll> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll curr = 0;
    ll ans = 0;
    deque<int> choices;
    while (!a.empty()) {
        if (curr + a.back() >= x) {
            curr = (curr + a.back()) % x;
            ans += a.back();
            choices.push_back(a.back());
            a.pop_back();
        } else {
            curr += a.front();
            choices.push_back(a.front());
            a.pop_front();
        }
    }
    cout << ans << '\n';
    for (int x : choices) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
