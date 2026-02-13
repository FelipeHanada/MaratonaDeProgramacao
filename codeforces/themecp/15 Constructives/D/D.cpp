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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> a[i][j];
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> b[i][j];

        auto rot = [&]() {
            vector<vector<int>> c(m, vector<int>(n));
            for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
                c[j][i] = a[i][j];
            }
            a = c;
            for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
                c[j][i] = b[i][j];
            }
            b = c;
            swap(n, m);
        };

        vector<vector<int>> c = a, d = b;
        for (int i=0; i<n; i++) {
            sort(c[i].begin(), c[i].end());
            sort(d[i].begin(), d[i].end());
        }
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        bool ok = 1;
        for (int i=0; i<n && ok; i++) {
            set<int> s;
            for (int j=0; j<m && ok; j++) s.insert(c[i][j]);
            for (int j=0; j<m && ok; j++) if (!s.count(d[i][j])) ok = 0;
        }

        rot();
        
        c = a, d = b;
        for (int i=0; i<n; i++) {
            sort(c[i].begin(), c[i].end());
            sort(d[i].begin(), d[i].end());
        }
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        for (int i=0; i<n && ok; i++) {
            set<int> s;
            for (int j=0; j<m && ok; j++) s.insert(c[i][j]);
            for (int j=0; j<m && ok; j++) if (!s.count(d[i][j])) ok = 0;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
