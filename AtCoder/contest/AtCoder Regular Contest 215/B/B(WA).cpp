#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        for (int i=0; i<2*n; i++) {
            cin >> a[i];
        }


        vector<int> ans;
        vector<bool> seen(n+1, 0);
        int i=0, j=0;
        int cnt = 0;
        vector<bool> marked(n+1, 0);

        while (i < 2*n) {
            while (j < 2*n && !seen[a[j]] && (cnt%2 || !marked[a[j]])) {
                seen[a[j]] = 1;
                if (!(cnt%2)) marked[a[j]] = 1;
                j++;
            }

            if (j < 2*n) ans.push_back(j - 1);

            while (i < j) {
                seen[a[i]] = 0;
                i++;
            }
            cnt = 1 - cnt;
        }

        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}
