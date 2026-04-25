#include <bits/stdc++.h>
using namespace std;


using ll = long long;
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = int(s.size());

        int ans = 0;
        ll small = 0;
        vector<ll> prefix(n+1);
        prefix[0] = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == 'B') prefix[i+1] = 1;
            else prefix[i+1] = -1;
            prefix[i+1] += prefix[i];

            if (prefix[i+1] < small) {
                ans = i + 1;
                small = prefix[i+1];
            }
        }

        cout << ans << '\n';
    }
}