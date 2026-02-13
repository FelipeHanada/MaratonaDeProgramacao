#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    deque<int> a(n);
    int zero = 0;
    int big = 0;
    for (int i=0; i<n; i++) {
        char x;
        cin >> x;
        a[i] = x - '0';
        if (a[i] == 0) zero++;
        big = max(big, a[i]);
    }

    if (n == 2) {
        cout << a[0]*10 + a[1] << '\n';
        return;
    }

    int ans = INT32_MAX;
    for (int i=0; i<n-1; i++) {
        int sum = 0;

        for (int j=0; j<n; j++) {
            if (j == i) sum += a[j]*10;
            else if (j == i+1) {
                if (a[j] == 1 && a[j-1] == 0) continue;
                if (a[j] == 0 && a[j-1] == 0) {
                    sum = 0;
                    break;
                }
                sum += a[j];
            }
            else if (a[j] == 0) {
                sum = 0;
                break;
            }
            else if (a[j] != 1 || (sum == 0 && big == 1)) {
                sum += a[j];
            }
        }
        ans = min(ans, sum);
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}