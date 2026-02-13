#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 2e5;
ll n, x, y, a, b, k;
ll tickets[MAX_N];


bool check(ll m) {
    // is possible to make k with just m tickets?
    ll abn = m / ((a * b) / __gcd(a, b));
    ll an = m / a - abn;
    ll bn = m / b - abn;

    ll contribution = 0;
    for (int i=0; i<m; i++) {
        if (abn) {
            contribution += tickets[n-i-1] * (x + y);
            abn--;
        } else if (an) {
            contribution += tickets[n-i-1] * x;
            an--;
        } else if (bn) {
            contribution += tickets[n-i-1] * y;
            bn--;
        }

        if (contribution >= k) return true;
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> tickets[i];
        tickets[i] /= 100;
    }
    sort(tickets, tickets+n);
    cin >> x >> a;
    cin >> y >> b;
    if (x < y) { // a is always better (for simplicity)
        swap(x, y);
        swap(a, b);
    }
    cin >> k;

    if (!check(n)) {
        cout << "-1\n";
        return;
    }

    int low = 0, high = n;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (!check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << high << '\n';
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
