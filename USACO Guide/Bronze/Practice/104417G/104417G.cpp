#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

void solve() {
    int n;
    cin >> n;

    map<int, stack<int>> v;
    int x;
    for (int i=1; i<=n; i++) {
        cin >> x;
        v.insert({x-i, {}}).f->s.push(x);
    }

    ll ans = 0;
    for (auto &t : v) {
        auto &stk = t.s;

        while (stk.size() > 1) {
            int w = stk.top(); stk.pop();
            w += stk.top(); stk.pop();
            
            if (w < 0) break;
            ans += w;
        }
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        solve();
    }
}