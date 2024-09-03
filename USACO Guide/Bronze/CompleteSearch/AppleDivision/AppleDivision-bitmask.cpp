#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    int p[n];
    for (int i=0; i<n; i++) cin >> p[i];

    ll min_weight = LONG_LONG_MAX;

    // (1 << n)  eq.  2^n
    for (int mask=0; mask < (1 << n); mask++) {
        ll left=0, right=0;

        for (int k=0; k<n; k++) {
            // mask & (1 << k) checks if the k'th bit in mask is 1
            if (mask & (1 << k)) left += p[k];
            else right += p[k];
        }

        min_weight = min(min_weight, abs(left - right));
    }

    cout << min_weight << endl;
}