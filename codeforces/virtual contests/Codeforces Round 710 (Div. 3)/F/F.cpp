#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;
    deque<pair<int, int>> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i].first;
    }
    for (int i=0; i<n; i++) {
        cin >> p[i].second;
    }
    sort(p.begin(), p.end());

    ll ans = 0;
    for (int i=0; i<n-1; i++) {
        // cost from p[i] => p[i+1]
        int d2 = p[i+1].second - p[i].second;
        int d1 = p[i+1].first - p[i].first - d2;
        // if (p[i].f - p[i+1].f == p[i].s)
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}