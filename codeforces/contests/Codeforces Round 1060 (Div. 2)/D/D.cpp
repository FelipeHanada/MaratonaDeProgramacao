#include <bits/stdc++.h>
using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n), parent(n);
    vector<int> children(n, 0);

    dist[0] = 0; parent[0] = -1;
    stack<pair<int, int>> dfs;
    dfs.push({0, 0});
    deque<int> even, odd;
    while (!dfs.empty()) {
        auto [curr, d]  = dfs.top();
        dfs.pop();
        for (int neighbor : adj[curr]) {
            if (neighbor == parent[curr]) continue;
            children[curr]++;
            dfs.push({neighbor, d+1});
            dist[neighbor] = d+1;
            parent[neighbor] = curr;
        }
        if (curr != n-1 && children[curr] == 0 && adj[curr].size() == 1) {
            if (dist[curr] % 2) odd.push_back(curr);
            else even.push_back(curr);
        }
    }

    set<int> in_path;
    deque<int> path;
    for (int i=n-1; i>=0; i = parent[i]) {
        in_path.insert(i);
        path.push_front(i);
    }

    deque<int> ans;
    bool in_even = true;
    while (even.size() + odd.size()) {
        if (in_even) {
            if (!odd.empty()) {
                int curr = odd.back();
                ans.push_back(curr);
                odd.pop_back();
                children[parent[curr]]--;
                if (children[parent[curr]] == 0 && !in_path.count(parent[curr]))
                    even.push_back(parent[curr]);
            }
        } else {
            if (!even.empty()) {
                int curr = even.back();
                even.pop_back();
                ans.push_back(curr);
                children[parent[curr]]--;
                if (children[parent[curr]] == 0 && !in_path.count(parent[curr]))
                    odd.push_back(parent[curr]);
            }
        }

        ans.push_back(-1);
        in_even = !in_even;
    }

    if (in_even) ans.push_back(-1);
    while (path.size() > 1) {
        ans.push_back(path.front());
        ans.push_back(-1);
        path.pop_front();
    }

    cout << ans.size() << '\n';
    for (int i : ans) {
        if (i == -1) {
            cout << "1\n";
        } else {
            cout << "2 " << i + 1 << '\n';
        }
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
