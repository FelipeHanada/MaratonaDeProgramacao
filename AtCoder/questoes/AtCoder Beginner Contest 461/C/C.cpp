#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());

    set<int> used;
    priority_queue<int> pq;
    int taken = 0;
    ll ans = 0;
    while (taken < k) {
        auto [v, c] = a.back(); a.pop_back();
        if (used.count(c)) pq.push(-v);
        used.insert(c);
        ans += v;
        taken++;

        if (taken == k && used.size() < m) {
            ans += pq.top(); pq.pop();
            taken--;
        }
    }

    cout << ans << '\n';
}