#include <bits/stdc++.h>
using namespace std;

typedef uint64_t u64;

/*
k = 2 is always optimal
since, for every partition with k > 2, we can sum all the left-side partitions (except the first)
and get atleast the same value
gcd(p1, p2, p3, ..., pk) <= gcd(p1, p2 + p3 + ... pk)
* because gcd(p1, p2, p3, ..., pk) is a common divisor for p1 and p2 + p3 + ... + pk

let the left sum be L and the right sum R
check for all possible L's and R's
*/

u64 solve(int n, vector<u64>& prefix) {
    u64 ans = 1;
    u64 l, r;
    for (int i = 0; i+1 < n; i++) {
        l = prefix[i+1]; r = prefix[n] - prefix[i+1];
        ans = max(ans, gcd(l, r));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        vector<u64> prefix(n+1);
        for (int j=0; j<n; j++) {
            cin >> prefix[j+1];
            prefix[j+1] += prefix[j];
        }

        cout << solve(n, prefix) << "\n";
    }
}
