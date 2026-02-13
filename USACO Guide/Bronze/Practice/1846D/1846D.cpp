#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n;
    double d, h;
    cin >> t;

    for (int ti=0; ti<t; ti++) {
        cin >> n >> d >> h;

        int x[n];
        for (int i=0; i<n; i++) cin >> x[i];
        sort(x, x+n);

        double ans = d * h;
        for (int i=0; i<n-1; i++) {
            ans += d * h;
            int dh = x[i] + h - x[i + 1];

            if (dh > 0) ans -= dh * (dh * d / h);
        }

        cout << fixed << setprecision(6) << ans / 2 <<  '\n';
    }
}
