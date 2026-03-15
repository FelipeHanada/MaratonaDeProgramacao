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
        vector<int> a(n), b(m);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];

        vector<int> cntA(n+m+1, 0), cnt(n+m+1, 0);

        for (int i=0; i<n; i++) cntA[a[i]]++;

        for (int i=1; i<=n+m; i++) {
            for (int j=i; j<=n+m; j+=i) {
                cnt[j] += cntA[i];
            }
        }

        int A = 0, B = 0, AB = 0;
        for (int i=0; i<m; i++) {
            if (cnt[b[i]] == n) A++;
            else if (cnt[b[i]] == 0) B++;
            else AB++;
        }
        
        if (A > B) {
            cout << "Alice\n";
        } else if (B > A) {
            cout << "Bob\n";
        } else {
            if (AB % 2) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        }
    }
}
