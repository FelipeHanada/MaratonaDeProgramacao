#include <bits/stdc++.h>
using namespace std;


using ll = long long;

#define _1 first
#define _2 second

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    int deg_sum = 0;
    vector<pair<int, int>> deg(n);
    for (int i=0; i<n; i++) {
        cin >> deg[i]._1;
        deg[i]._2 = i;
        deg_sum += deg[i]._1;
    }
    sort(deg.begin(), deg.end());

    if (deg_sum/2 < n - 1 || (deg[0]._1 == 1 && deg.back()._1 == 1)) {
        cout << "NO\n";
        return 0;
    }

    auto ub = upper_bound(deg.begin(), deg.end(), make_pair(1, INT32_MAX));
    int start = max(2, (int)distance(deg.begin(), ub));

    deque<pair<int, int>> dq;
    for (int i=start; i<n; i+=2) {
        dq.push_front(deg[i]);
        if (i + 1 < n) dq.push_back(deg[i + 1]);
    }

    vector<pair<int, int>> edges;
    vector<vector<int>> adj(n);
    for (int i=0; i<dq.size()-1; i++) {
        adj[dq[i]._2].push_back(dq[i+1]._2);
        adj[dq[i+1]._2].push_back(dq[i]._2);
        edges.push_back({dq[i]._2, dq[i+1]._2});
    }

    if (dq.size() > 1) {
        dq.front()._1--;
        for (int i=1; i<dq.size()-1; i++) {
            dq[i]._1 -= 2;
        }
        if (dq.size() > 1) dq.back()._1--;
    }

    bool front = 1;
    for (int i=0; i<start; i++) {
        if (dq.front()._1 == dq.back()._1 && dq.front()._1 == 0) {
            dq.pop_back();
            if (!dq.empty()) dq.pop_front();
        }
        if (dq.back()._1 == 0 || (front && dq.front()._1)) {
            adj[deg[i]._2].push_back(dq.front()._2);
            adj[dq.front()._2].push_back(deg[i]._2);
            edges.push_back({deg[i]._2, dq.front()._2});
            dq.front()._1--;
            front = 0;
        } else { // dq.back() && (!front || dq.front()._1 == 0)
            adj[deg[i]._2].push_back(dq.back()._2);
            adj[dq.back()._2].push_back(deg[i]._2);
            edges.push_back({deg[i]._2, dq.back()._2});
            dq.back()._1--;
            front = 1;
        }
    }

    auto dist = [&](int start) -> pair<int, int> {
        queue<pair<int, int>> q; q.push({start, 0});
        vector<bool> seen(n, 0); seen[start] = 1;

        pair<int, int> ans = { -1, -1 };
        while (!q.empty()) {
            auto [curr, d] = q.front(); q.pop();
            ans = { curr, d };

            for (int neighbor : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                q.push({neighbor, d+1});
            }
        }

        return ans;
    };

    pair<int, int> r = dist(0);
    r = dist(r._1);

    cout << "YES " << r._2 << '\n';
    cout << edges.size() << '\n';
    for (auto [x, y] : edges) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
}
