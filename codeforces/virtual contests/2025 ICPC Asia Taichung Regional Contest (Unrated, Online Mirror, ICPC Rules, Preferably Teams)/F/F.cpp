#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    deque<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    deque<int> prefix(n), suffix(n);
    prefix[0] = p[0];
    for (int i=1; i<n; i++) {
        prefix[i] = __gcd(prefix[i-1], p[i]);
    }
    suffix[n-1] = p[n-1];
    for (int i=n-2; i>=0; i--) {
        suffix[i] = __gcd(suffix[i+1], p[i]);
    }

    long long ans = prefix[n-1];
    for (int i=1; i<n-1; i++) {
        ans += min(prefix[i], suffix[i]);
    }

    cout << ans << '\n';
}
