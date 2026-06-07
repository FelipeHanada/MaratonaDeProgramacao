#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int i=0, j = n-1;
        int ans = 0;
        while (i < j && a[i] != a[j]) {
            ans++;
            i++;
            j--;
        }

        cout << ans << '\n';
    }
}
