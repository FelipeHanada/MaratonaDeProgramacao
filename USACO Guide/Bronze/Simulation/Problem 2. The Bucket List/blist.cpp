#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> evt;
    int s, t, b;
    for (int i=0; i<n; i++) {
        cin >> s >> t >> b;
        evt.push_back(make_pair(s, b));
        evt.push_back(make_pair(t, -b));
    }
    sort(evt.begin(), evt.end());

    int ans = 0;
    int buckets = 0;
    int time;
    while (!evt.empty()) {
        time = evt.begin()->first;

        while (!evt.empty() && time == evt.begin()->first) {
            buckets += evt.begin()->second;
            evt.erase(evt.begin());
        }

        ans = max(ans, buckets);
    }

    cout << ans << '\n';
}
