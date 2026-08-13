#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            ans[n-a[i]] = i;
        }

        for (int x : ans) cout << x + 1 << ' ';
        cout << '\n';
    }
}
