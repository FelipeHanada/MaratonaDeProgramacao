#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> f(n);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x <= k) f[i] = 1;
        else f[i] = -1;
    }
    vector<int> prefix(n), suffix(n);
    vector<int> big_suffix(n), small_prefix(n), small_suffix(n);
    prefix[0] = small_prefix[0] = f.front();
    suffix[n-1] = big_suffix[n-1] = small_suffix[n-1] = f.back();

    for (int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] + f[i];
        suffix[n-i-1] = suffix[n-i] + f[n-i-1];

        small_prefix[i] = min(small_prefix[i-1], prefix[i]);
        small_suffix[n-i-1] = min(small_suffix[n-i], suffix[n-i]);
        big_suffix[n-i-1] = max(big_suffix[n-i], suffix[n-i]);
    }

    /*
    I) f(1)+...+f(l), f(l+1)+...+f(r) >= 0
        for the first prefix[i] >= 0
            we check if exists a suffix[i+1] - suffix[j] (i+2<=j<n)
                this can be done by checking if suffix[i+1] - small_suffix[i+2] >= 0
    II) f(1)+...+f(l), f(r+1)+...+f(n) >= 0
        for the first prefix[i] >= 0
            we check if exists a suffix[j]>=0 (j>=i+2)
                this can be done verifying big_suffix[i+2] >= 0
    III) f(l+1)+...+f(r), f(r+1)+...+f(n) >= 0
        for the last suffix[i] >= 0
            we check if exists a prefix[i-1] - prefix[j] (0<=j<=i-2)
                this can be done by checking if prefix[i-1] - small_prefix[i-2] >= 0
    */

    for (int i=0; i + 2 < n; i++) if (prefix[i] >= 0) {
        if (suffix[i+1] - small_suffix[i+2] >= 0) {
            cout << "YES\n";
            return;
        }
        if (big_suffix[i+2] >= 0) {
            cout << "YES\n";
            return;
        }
    }

    for (int i=n-1; i - 2 >= 0; i--) if (suffix[i] >= 0) {
        if (prefix[i-1] - small_prefix[i-2] >= 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}