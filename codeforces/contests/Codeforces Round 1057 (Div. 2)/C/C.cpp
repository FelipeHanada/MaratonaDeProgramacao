#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;
    map<ll, int> edges;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        edges[x]++;
    }

    deque<int> odds;
    ll sum = 0;
    int edge_count = 0;
    for (auto [x, c] : edges) {
        if (c % 2) {
            odds.push_back(x);
        }
        sum += c / 2 * 2 * x;
        edge_count += c / 2 * 2;
    }

    while (!odds.empty()) {
        if (odds.size() >= 2) sum += odds[odds.size()-2];
        edge_count++;
        if (sum > odds.back()) break;
        if (odds.size() >= 2) sum -= odds[odds.size()-2];
        edge_count--;
        odds.pop_back();
    }

    if (!odds.empty() && sum > odds.back()) {
        sum += odds.back();
        edge_count++;
    }

    if (edge_count > 2) {
        cout << sum << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
