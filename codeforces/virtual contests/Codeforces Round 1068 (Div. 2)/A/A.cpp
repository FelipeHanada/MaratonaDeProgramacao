#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

void precompute() {
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = 0;
    int last_awake = INT32_MIN;
    for (int i=0; i<n; i++) {
        if (s[i] == '1') last_awake = i;
        if (last_awake + k >= i) continue; // cannot sleep
        else ans++;
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
