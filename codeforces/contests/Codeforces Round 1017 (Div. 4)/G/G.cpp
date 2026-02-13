#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int q;
    cin >> q;

    deque<int> a;
    ll sum = 0;
    ll ans = 0;
    bool reversed = false;
    while (q--) {
        int s, x;
        cin >> s;
        if (s == 1) {
            if (!reversed) {
                ans += (sum - a.back() - a.back() * a.size()) + a.back();
                a.push_front(a.back());
                a.pop_back();
            } else {
                ans += (sum - a.front() - a.front() * a.size()) + a.front();
                a.push_back(a.front());
                a.pop_front();
            }
        } else if (s == 2) {
            ans = (a.size() + 1) * sum - ans;
            reversed = !reversed;
        } else {
            cin >> x;
            if (!reversed) a.push_back(x);
            else a.push_front(x);
            sum += x;
            ans += x * a.size();
        }

        cout << ans << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
