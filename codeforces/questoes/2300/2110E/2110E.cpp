#include <bits/stdc++.h>
using namespace std;


#define _1 first
#define _2 second

void solve() {
    int n;
    cin >> n;
    set<int> v, p;
    vector<pair<int, int>> edges(n);
    for (int i=0; i<n; i++) {
        cin >> edges[i]._1 >> edges[i]._2;
        v.insert(edges[i]._1);
        p.insert(edges[i]._2);
    }

    map<int, int> vcomp, pcomp;
    {
        int i=0;
        for (int x : v) {
            vcomp[x] = i++;
        }
        for (int x : p) {
            pcomp[x] = i++;
        }
    }

    map<pair<int, int>, int> edges_inv;
    vector<multiset<int>> adj(v.size()+p.size());
    for (int i=0; i<n; i++) {
        edges[i]._1 = vcomp[edges[i]._1];
        edges[i]._2 = pcomp[edges[i]._2];
        edges_inv[edges[i]] = i;
        edges_inv[{edges[i]._2, edges[i]._1}] = i;

        adj[edges[i]._1].insert(edges[i]._2);
        adj[edges[i]._2].insert(edges[i]._1);
    }

    int start = -1, end = -1;
    for (int i=0; i<v.size()+p.size(); i++) {
        if (adj[i].size() & 1) {
            if (start == -1) start = i;
            else if (end == -1) end = i;
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    if (start != -1) {
        // adds a virtual vertex

        int new_vertex = adj.size();
        adj.push_back({start, end});

        adj[start].insert(new_vertex);
        adj[end].insert(new_vertex);

        edges.push_back({start, new_vertex});
        edges.push_back({end, new_vertex});
        edges_inv[{start, new_vertex}] = edges_inv[{new_vertex, start}] = n;
        edges_inv[{end, new_vertex}] = edges_inv[{new_vertex, end}] = n+1;
    } else {
        start = 0;
    }

    int virtual_edge = -1;
    vector<int> ans; // edges of a eulerian circuit
    stack<int> stk;
    stk.push(start);
    while (!stk.empty()) {
        auto curr = stk.top();
        if (adj[curr].empty()) {
            stk.pop();
            if (!stk.empty()) {
                if (edges_inv[{curr, stk.top()}] >= n) {
                    virtual_edge = ans.size();
                }
                ans.push_back(edges_inv[{curr, stk.top()}]);
            }
        } else {
            auto next = *adj[curr].begin();
            adj[curr].extract(next);
            adj[next].extract(curr);
            stk.push(next);
        }
    }

    if (ans.size() < edges.size()) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (virtual_edge == -1) {
        // no virtual vertex was added
        for (int x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    } else {
        // ignore virtual vertex

        for (int i=virtual_edge-2; i>=0; i--) {
            cout << ans[i] + 1 << ' ';
        }

        for (int i=ans.size()-1; i>virtual_edge; i--) {
            cout << ans[i] + 1 << ' ';
        }

        cout << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}