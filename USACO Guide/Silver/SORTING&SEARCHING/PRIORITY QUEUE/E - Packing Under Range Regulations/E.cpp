#include <bits/stdc++.h>
using namespace std;


void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    auto cmp = [&](int i, int j) -> bool {
        return a[i].second > a[j].second;
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    int last = -1;
    int i=0;
    while (i < n || !pq.empty()) {
        if (i < n && pq.empty()) pq.push(i++);

        while (i < n && last + 1 >= a[i].first) {
            pq.push(i++);
        }

        int curr = pq.top(); pq.pop();
        if (a[curr].second <= last) {
            cout << "No\n";
            return;
        }
        last = max(last + 1, a[curr].first);
    }

    cout << "Yes\n";
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
