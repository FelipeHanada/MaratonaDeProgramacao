#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> a[i][j];
            }
        }

        vector<int> ans(n, (1<<30)-1);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                ans[i] &= a[i][j];
                ans[j] &= a[i][j];
            }
        }

        bool ok = 1;
        for (int i=0; ok && i<n; i++) {
            for (int j=i+1; ok && j<n; j++) {
                if ((ans[i] | ans[j]) != a[i][j]) ok = 0;
            }
        }

        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int x : ans) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}
