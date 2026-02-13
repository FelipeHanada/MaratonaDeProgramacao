#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> prefix(n);
    vector<int> suffix(n);
    for (int i=0; i<n; i++) {
        cin >> prefix[i];
        suffix[i] = prefix[i];
    }
    for (int i=1; i<n; i++) {
        prefix[i] = __gcd(prefix[i-1], prefix[i]);
    }
    for (int i=n-2; i>=0; i--) {
        suffix[i] = __gcd(suffix[i+1], suffix[i]);
    }

    int best = max(prefix[n-2], suffix[1]);
    for (int i=1; i<n-1; i++) {
        best = max(best, __gcd(prefix[i-1], suffix[i+1]));
    }

    cout << best << '\n';
}
