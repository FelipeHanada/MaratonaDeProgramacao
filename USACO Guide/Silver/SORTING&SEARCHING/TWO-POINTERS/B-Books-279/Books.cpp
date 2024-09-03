#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll t;
    cin >> n >> t;

    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int left = 0, right = 0;
    ll current_t = 0;
    while (left < n && right < n) {
        while (right < n) {
            current_t += a[right++];

            if (current_t > t) {
                current_t -= a[--right];
                break;
            }
        }

        ans = max(ans, right - left);
        current_t -= a[left++];
    }

    cout << ans << endl;
}
