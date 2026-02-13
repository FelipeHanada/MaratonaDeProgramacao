#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll l, r;
ll c_mult(ll x) {
    return (r/x) - ((l+(x-1))/x);
}

void solve() {
    cin >> l >> r;
    // we need to count the numbers that are
    // multiple by 2, 3, 5 or 7 inside [l, r]
    // to do this we use principle of inclusion exclusion
    // let f(x) be the amount of numbers multiple by x inside [l, r]
    // we need to compute X= f(2)+f(3)+f(5)+f(7)-f(6)-f(10)-f(14)-f(15)-f(21)-f(35)+f(30)+f(42)+f(70)+f(105)-f(210)
    // the number of good numbers inside this will be r-l-X

    ll singles = c_mult(2) + c_mult(3) + c_mult(5) + c_mult(7);
    ll doubles = c_mult(6) + c_mult(10) + c_mult(14) + c_mult(15) + c_mult(21) + c_mult(35);
    ll triples = c_mult(30) + c_mult(42) + c_mult(70) + c_mult(105);
    ll quadruples = c_mult(210);
    cout << r-l-(singles - doubles + triples - quadruples) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}