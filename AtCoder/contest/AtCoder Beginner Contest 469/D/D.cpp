#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> adj(m);
    vector<int> cnt(n, 0);
    for (int i=0; i<m; i++) {
        cin >> adj[i].first >> adj[i].second;
        adj[i].first--;
        adj[i].second--;
        cnt[adj[i].first]++;
        cnt[adj[i].second]++;
    }

    set<int> cand;
    for (int i=0; i<n; i++) if (cnt[i] >= (m+1)/2) {
        cand.insert(i);
    }

    int ans = 0;
    for (int x : cand) {
        set<int> curr;
        for (int i=0; i<n; i++) if (i != x) {
            if (cand.count(i) && i < x) continue;
            curr.insert(i);
        }

        for (auto [ i, j ] : adj) {
            if (i == x || j == x) continue;

            set<int> next;
            if (curr.count(i)) next.insert(i);
            if (curr.count(j)) next.insert(j);

            swap(curr, next);
        }

        ans += curr.size();
    }

    cout << ans << '\n';
}
