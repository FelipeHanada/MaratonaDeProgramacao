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
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        vector<int> v(k);
        for (int i=0; i<k; i++) cin >> v[i];

        vector<int> pre(k+1);
        pre[0] = 0;
        for (int i=1; i<=k; i++) pre[i] = pre[i-1] + bool(v[i]);

        int ans = 0;
        for (int i=0; i<=min(n, d-1); i++) {
            int score = 0;
            for (int j=0; j<n; j++) score += (a[j] == j + 1);

            int curr_d = d - i - 1;

            
            
            ans = max(ans, score);

            for (int j=0; j<v[i%n]; j++) a[j]++;
        }

        cout << ans << '\n';
    }
}
