#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<int> prefix(n), suffix(n);
    for (int i=0; i<n; i++) {
        prefix[i] = suffix[i] = x;
        x = ((ll)a * x + b) % c;
    }

    for (int i=0; i<n; i+=k) {
        for (int j=1; j<k && i+j<n; j++) {
            prefix[i+j] |= prefix[i+j-1];
        }
        for (int j=min(k-2, n-i); j>=0; j--) {
            suffix[i+j] |= suffix[i+j+1];
        }
    }

    int ans = 0;
    for (int i=k-1; i<n; i++) {
        ans ^= prefix[i] | suffix[i-k+1];
    }
    cout << ans << '\n';
}
