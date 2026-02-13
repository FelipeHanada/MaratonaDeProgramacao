#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> s;
    unordered_map<int, int> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    int k=0;
    for (int x : s) {
        m[x] = k++;
    }

    vector<ll> dp(n, 0), next(n);
    for (int i=0; i<m[a[0]]; i++) dp[i] = b[0];
    for (int i=m[a[0]]; i<k; i++) dp[i] = 0;

    // dp[i][j] = minimum cost until i'th element
    //              with the last element at most j

    for (int i=0; i<n-1; i++) {
        next[0] = dp[0] + (b[i+1])*(m[a[i+1]] != 0);
        for (int j=1; j<k; j++) {
            next[j] = min(next[j-1], dp[j] + (b[i+1])*(m[a[i+1]] != j));
        }
        swap(dp, next);
    }

    cout << dp[k-1] << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
