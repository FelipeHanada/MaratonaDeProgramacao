#include <bits/stdc++.h>
using namespace std;


void precompute() {

}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    int i=0, j=n-1;
    for (; i<n && s[i] == '0'; i++) {
        ans++;
    }
    for (; j>=0 && s[j] == '0'; j--) {
        ans++;
    }

    int curr = 0;
    for (int k=i+1; k<=j; k++) {
        if (s[k] == '0') {
            curr++;
        } else {
            ans = max(ans, curr);
            curr = 0;
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