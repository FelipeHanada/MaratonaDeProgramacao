#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int lcm(int a, int b) {
    return (ll(a) * b) / __gcd(a, b);
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        int ans = 0;
        if (__gcd(a[0], a[1]) < a[0]) {
            ans++;
            a[0] = __gcd(a[0], a[1]);
        }

        if (__gcd(a[n-2], a[n-1]) < a[n-1]) {
            ans++;
            a[n-1] = __gcd(a[n-2], a[n-1]);
        }

        for (int i=1; i<n-1; i++) {
            if (lcm(__gcd(a[i-1], a[i]), __gcd(a[i], a[i+1])) < a[i]) {
                ans++;
                a[i] = lcm(__gcd(a[i-1], a[i]), __gcd(a[i], a[i+1]));
            }
        }

        cout << ans << '\n';
    }
}
