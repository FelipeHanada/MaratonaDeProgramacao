#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(ll left, ll right, int n, int *v) {
    if (n <= 0) return abs(left - right);

    return min(
        solve(left + v[0], right, n-1, v+1),
        solve(left, right + v[0], n-1, v+1)
    );
}

int main() {
    int n;
    cin >> n;

    int v[n];
    for (int i=0; i<n; i++) cin >> v[i];

    cout << solve(0, 0, n, v) << endl;
}
