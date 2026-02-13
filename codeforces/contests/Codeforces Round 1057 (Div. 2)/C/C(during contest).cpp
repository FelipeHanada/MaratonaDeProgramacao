#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve() {
    int n;
    cin >> n;
    map<int, int> edge_count;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        edge_count[x]++;
    }

    ll sum = 0;
    map<ll, ll> edge_sum;
    deque<ll> odds;
    for (auto [x, c] : edge_count) {
        edge_sum[x] = sum;
        sum += x * (c / 2 * 2);
        if (c % 2) {
            if (odds.size() >= 2) sum -= odds.front();
            sum += x; // os dois odds são esse e o ultimo
            if (odds.size() >= 2) odds.pop_front();
            odds.push_back(x);
        }
    }


    map<ll, ll> rev_edge_count;
    for (auto [x, c] : edge_count) {
        rev_edge_count[-x] = c;
    }
    
    set<ll> starts;
    for (auto [x, c] : rev_edge_count) {
        if (-x < edge_sum[-x] - x * (c - 1) || edge_sum[-x] == 0) {
            starts.insert(x);
        }
    }

    ll best = 0;
    for (auto i : starts) {
        auto it = rev_edge_count.find(i);
        ll edges = 0;
        ll curr = 0;
        ll odd_count = 0;

        for (; it != rev_edge_count.end(); it++) {
            curr += (it->second / 2) * 2 * it->first;
            edges += (it->second / 2) * 2;
            if (odd_count < 2 && it->second % 2) {
                odd_count++;
                curr += it->first;
                edges++;
            }
        }

        if (edges > 2) {
            best = max(best, -curr);
        }
    }

    cout << best << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
