#include <bits/stdc++.h>
using namespace std;


#define ll long long

/*
Let a valid state (a,b)

if a<b, then the only other valid state that can be moved into (a,b) is only (d,c)
    with d=2*a and c the rest

proof. consider the state (a,b) with a<b.
    the only two states that (a,b) can come from is:
        (2*a,a+b-2*a) and (a+b-2*b,2*b), that is
        (2a,b-a) and (a-b,2b)
        if a<b, then the state (a-b,2b) has a negative number of cakes
*/

void solve() {
    ll k, x;
    cin >> k >> x;

    ll a = x, b = ((ll)1<<(k+1))-a;
    stack<int> ans;
    while (a != b) {
        if (a < b) {
            ans.push(1);
            tie(a, b) = make_tuple(2*a, b-a);
        } else {
            ans.push(2);
            tie(a, b) = make_tuple(a-b, 2*b);
        }
    }

    cout << ans.size() << '\n';
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
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
