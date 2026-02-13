#include <bits/stdc++.h>
using namespace std;


#define ll long long

int n, k;
deque<deque<int>> adj(n);
ll ans;
deque<int> subtree;
ll subk = 0; // number of subtrees os size at least k in the current tree

void solve2(int i, int p) {
    // changes current state (rooted at p) to a tree rooted at i (i must be adjacent to p)
    int delta = 0;

    if (subtree[i] >= k) delta--;
    
    tuple<int, int> last = {subtree[i], subtree[p]};
    subtree[p] -= subtree[i];
    subtree[i] = n;

    if (subtree[p] >= k) delta++;

    subk += delta;
    ans += subk;

    for (int neighbor : adj[i]) {
        if (neighbor == p) continue;
        solve2(neighbor, i);
    }

    subk -= delta;
    tie(subtree[i], subtree[p]) = last;
}

void solve() {
    cin >> n >> k;
    adj.assign(n, deque<int>());
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // calculate size of subtrees rooted at 0
    subtree.assign(n, 0);
    subk = 0;
    {
        deque<pair<int, int>> bfs;
        bfs.push_back({0, -1});
        int i=0;
        while (i < bfs.size()) {
            auto [curr, p] = bfs[i++];
            for (int neighbor : adj[curr]) {
                if (neighbor == p) continue;
                bfs.push_back({neighbor, curr});
            }
        }

        subtree[0]++;
        subk++;
        for (int i=n-1; i>0; i--) {
            auto [curr, p] = bfs[i];
            subtree[curr]++;
            if (p >= 0)
                subtree[p] += subtree[curr];
            if (subtree[curr] >= k) subk++;
        }
    }
    ans = subk;

    for (int neighbor : adj[0]) {
        solve2(neighbor, 0);
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
