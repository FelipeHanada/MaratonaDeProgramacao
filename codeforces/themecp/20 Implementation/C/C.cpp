#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        map<int, set<int>> m;
        for (int i=0; i<n; i++) {
            m[a[i]].insert(i);
        }

        vector<vector<pair<int, int>>> ranges;
        while (!m.empty()) {
            auto [ x, s ] = *m.rbegin();

            vector<pair<int, int>> r;
            for (int i : s) {
                if (r.empty() || r.back().second < i - 1) {
                    r.push_back({i, i});
                } else {
                    r.back().second++;
                }
            }
            ranges.push_back(r);

            m.erase(x);
        }

        int ans = 0;
        for (auto r : ranges) {
            for (pair<int, int> range : r) {
                auto [s, t] = range;
                if ((s && a[s-1] == -1) || (t < n-1 && a[t+1] == -1)) {}
                else {
                    ans++;
                }

                for (int i=s; i<=t; i++) a[i] = -1;
            }
        }

        cout << ans << '\n';
    }    
}