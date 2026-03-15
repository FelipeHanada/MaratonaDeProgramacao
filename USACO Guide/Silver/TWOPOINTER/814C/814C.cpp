#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; string s;
    cin >> n >> s;
    int q;
    cin >> q;

    while (q--) {
        int k; char c;
        cin >> k >> c;

        int ans = 0;
        int skipped = 0;
        int i = 0, j = 0;
        while (i < n) {
            while (j < n && (skipped < k || s[j] == c)) {
                skipped += s[j] != c;
                j++;
            }

            ans = max(ans, j - i);
            skipped -= s[i] != c;
            i++;
        }

        cout << ans << '\n';
    }
}