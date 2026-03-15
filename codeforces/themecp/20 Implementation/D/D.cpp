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
        int n; string s;
        cin >> n >> s;
        vector<int> p(n);
        for (int i=0; i<n; i++) {
            cin >> p[i];
            p[i]--;
        }

        vector<bool> seen(n, 0);
        vector<int> sizes;
        for (int i=0; i<n; i++) {
            if (seen[i]) continue;
            string t;
            int curr = i;
            while (!seen[curr]) {
                seen[curr] = 1;
                t.push_back(s[curr]);
                curr = p[curr];
            }

            int size;
            for (int k=1; k<=t.size(); k++) {
                if (t.size() % k) continue;

                bool ok = 1;
                for (int j=0; ok && j<t.size(); j++) {
                    ok = (t[j] == t[(j+k)%t.size()]);
                }

                if (ok) {
                    size = k;
                    break;
                }
            }

            sizes.push_back(size);
        }

        // ans = lcm(sizes);

        ll ans = 1;
        for (int size : sizes) {
            ans = ans * size / __gcd(ans, (ll)size);
        }

        cout << ans << '\n';
    }
}