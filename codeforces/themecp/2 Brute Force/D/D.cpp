#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> suff(n, 0);
        vector<vector<int>> a(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> a[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=n-1; j>=0; j--) {
                if (a[i][j] != 1) break;
                suff[i]++;
            }
        }

        multiset<int> ms;
        for (int i=0; i<n; i++) ms.insert(suff[i]);
        int ans = 1;
        while (!ms.empty()) {
            int curr = *ms.begin();
            if (curr  >= ans) {
                ans++;
            }
            ms.extract(curr);
        }

        cout << min(n, ans) << '\n';
    }
}
