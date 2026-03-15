#include <bits/stdc++.h>
using namespace std;



using ll = long long;
#define _1 first
#define _2 second


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    // ans = n - max(longest inc subseq, longest dec subseq);

    int ans = INT32_MAX;
    {
        vector<int> lis; lis.push_back(INT32_MIN);
        for (int i=1; i<n-1; i++) {
            auto lb = lower_bound(lis.begin(), lis.end(), a[i]);
            if (lb == lis.end()) {
                lis.push_back({ a[i] });
            } else if (lb != lis.begin()) {
                (*lb) = a[i];
            }
        }

        ans = min(ans, n - int(lis.size() - 1) - 2 + (lis.back() >= a.back()));
    }
    {
        reverse(a.begin(), a.end());
        vector<int> lis; lis.push_back(INT32_MIN);
        for (int i=1; i<n-1; i++) {
            auto lb = lower_bound(lis.begin(), lis.end(), a[i]);
            if (lb == lis.end()) {
                lis.push_back({ a[i] });
            } else if (lb != lis.begin()) {
                (*lb) = a[i];
            }
        }
        ans = min(ans, n - int(lis.size() - 1) - 2 + (lis.back() >= a.back()));
    }

    cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) solve();
}
