#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> u(n), s(n);
        for (int i=0; i<n; i++) cin >> u[i];
        for (int i=0; i<n; i++) cin >> s[i];
        vector<vector<int>> a(n);
        for (int i=0; i<n; i++) {
            a[u[i]-1].push_back(s[i]);
        }
        vector<vector<ll>> prefix(n);
        for (int i=0; i<n; i++) {
            sort(a[i].rbegin(), a[i].rend());
            prefix[i].push_back(0);
            for (int j : a[i]) {
                prefix[i].push_back(prefix[i].back() + j);
            }
        }

        vector<ll> ans(n+1, 0);
        for (int i=0; i<n; i++) {
            int size = prefix[i].size()-1;
            for (int k=1; k<prefix[i].size(); k++) {
                // j must be divisible by k
                ans[k] += prefix[i][size - size%k];
            }
        }

        for (int i=1; i<=n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}
