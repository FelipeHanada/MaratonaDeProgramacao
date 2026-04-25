#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<int> ans(n, 0);
        for (int i=0; i<n; i++) {
            int big = 0, small = 0;
            for (int j=i+1; j<n; j++) {
                if (a[j] > a[i]) big++;
                else if (a[j] < a[i]) small++;
            }

            ans[i] = max(big, small);
        }

        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}
