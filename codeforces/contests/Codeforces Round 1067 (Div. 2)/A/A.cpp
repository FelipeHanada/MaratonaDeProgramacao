#include <bits/stdc++.h>
using namespace std;

#define _1 first
#define _2 second
#define pii pair<int, int>
#define ll long long 


void precompute() {

}

void solve() {
    int n;
    cin >> n;
    int y, r;
    cin >> y >> r;
    cout << min(n, y / 2 + r) << '\n';
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
