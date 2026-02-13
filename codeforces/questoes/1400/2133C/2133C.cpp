#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    priority_queue<pair<int, int>> pq;
    for (int i=1; i<=n; i++) {
        cout << "? " << i << ' ' << n << ' ';
        for (int i=1; i<=n; i++) cout << i << ' ';
        cout << '\n';
        fflush(stdout);
        int x;
        cin >> x;
        pq.push({x, i});
    }

    vector<int> ans;
    ans.push_back(pq.top().first);
    ans.push_back(pq.top().second);
    int remaining = pq.top().first - 1; pq.pop();
    while (remaining) {
        while (pq.top().first > remaining) pq.pop();
        cout << "? " << ans.back() << " 2 " << ans.back() << ' ' << pq.top().second << '\n';
        fflush(stdout);
        int x;
        cin >> x;
        if (x == 2) {
            ans.push_back(pq.top().second);
            remaining--;
        }
        pq.pop();
    }

    cout << "! ";
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
