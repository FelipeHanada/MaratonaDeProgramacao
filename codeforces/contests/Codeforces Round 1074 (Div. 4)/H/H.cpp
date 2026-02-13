#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int> p(n+1);
    p[0] = 0;
    for (int i=1; i<=n; i++) {
        p[i] = p[i-1] + a[i-1];
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
