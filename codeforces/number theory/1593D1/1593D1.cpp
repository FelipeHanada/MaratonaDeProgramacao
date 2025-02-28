#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>& a, int low) {
    // the problem is equivalent to find the largest k such that 
    // all a_i mod k = x

    int g = 0;
    for (int ai : a)
        g = __gcd(g, ai - low);

    if (!g) return -1;
    return g;
}

int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        vector<int> a(n);
        int low = INT32_MAX;
        for (int j=0; j<n; j++) {
            cin >> a[j];
            low = min(low, a[j]);
        }
        cout << solve(a, low) << "\n";
    }
}
