#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    double ans0 = 1, ans1 = 0;

    for (int i=0; i<n; i++) {
        double fail = (double)min(a[i], k-1) / a[i];
        double success = 1 - fail;

        double next0 = ans0 * fail;
        double next1 = ans0 * success + ans1;

        ans0 = next0;
        ans1 = next1;
    }

    cout << fixed << setprecision(10) << ans1 << '\n';
}