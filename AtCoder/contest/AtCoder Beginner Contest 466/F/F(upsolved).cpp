#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt; cin >> tt;
    while (tt--) {
        int n; ll x; cin >> n >> x;
        priority_queue<pair<ll, ll>> a;
        a.push({ x, 1 });

        for (int i=0; i<n; i++) {
            ll ai; cin >> ai;

            while (a.top().first >= ai) {
                auto [ x, cnt ] = a.top(); a.pop();

                while (!a.empty() && a.top().first == x) {
                    cnt += a.top().second;
                    a.pop();
                }

                if (x / ai) a.push({ ai-1, cnt * (x / ai) });
                a.push({ x % ai, cnt });
            }
        }

        ll ans = 0;
        while (!a.empty()) {
            auto [ x, cnt ] = a.top(); a.pop();
            ans += cnt;
        }
        cout << ans - 1 << '\n';
    }
}
