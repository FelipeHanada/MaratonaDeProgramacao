#include <bits/stdc++.h>
using namespace std;


void precompute() {

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (a[i] > a[j]) {
                ans++;
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}