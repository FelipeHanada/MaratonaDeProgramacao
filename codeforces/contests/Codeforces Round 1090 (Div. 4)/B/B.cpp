#include <bits/stdc++.h>
using namespace std;

#define _f first
#define _s second
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        vector<int> a(7);
        int sum = 0;
        for (int i=0; i<7; i++) {
            cin >> a[i];
            sum += - a[i];
        }

        int ans = INT32_MIN;
        for (int i=0; i<7; i++) {
            ans = max(ans, sum + 2 * a[i]);
        }
        cout << ans << '\n';
    }
}
