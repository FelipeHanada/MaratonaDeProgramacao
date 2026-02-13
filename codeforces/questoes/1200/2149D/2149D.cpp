#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> cost(n, 0);
    ll costA = 0, costB = 0;
    ll countA = 0, countB = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'a') {
            cost[i] = costA;
            countA++;
            costB += countB;
        } else {
            cost[i] = costB;
            countB++;
            costA += countA;
        }
    }
    countA = countB = 0;
    costA = costB = 0;
    for (int i=n-1; i>=0; i--) {
        if (s[i] == 'a') {
            cost[i] += costA;
            countA++;
            costB += countB;
        } else {
            cost[i] += costB;
            countB++;
            costA += countA;
        }
    }

    ll ans = INT64_MAX;
    for (int i=0; i<n; i++) {
        ans = min(ans, cost[i]);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}