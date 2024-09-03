#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    int n;
    cin >> n;

    int x;
    vector<ll> prefix(1, 0);
    for (int i=0; i<n; i++) {
        cin >> x;
        prefix.push_back(prefix[i] + x);
    }

    ll max_sum = INT32_MIN;
    ll min_prefix = 0;
    for (int r=1; r<=n; r++) {
        max_sum = max(max_sum, prefix[r] - min_prefix);
        min_prefix = min(min_prefix, prefix[r]);
    }

    cout << max_sum << endl;
}