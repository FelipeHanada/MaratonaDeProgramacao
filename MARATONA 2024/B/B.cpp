#include <bits/stdc++.h>
using namespace std;

/*
we can describe it as a bipartite graph

since he does not care about the way we connect the two actors
we can simply build a tree for every disconnected component of the graph
it can be done in O(M+N) using simple BFS (i think its preferable to minimize height) or DFS

*/


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+m);
    for (int i=0; i<n; i++) {
        int k, x;
        cin >> k;
        for (int j=0; j<k; j++) {
            cin >> x; x--;
            adj[i].push_back(x+n);
            adj[x+n].push_back(i);
        }
    }

    vector<int> comp(n+m, -1);
    vector<int> parent(n+m, -1);
    int id = 0;
    for (int i=0; i<n; i++) {
        if (comp[i] >= 0) continue;

        queue<int> q;
        q.push(i);
        comp[i] = id++;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (comp[neighbor] >= 0) continue;
                comp[neighbor] = comp[curr];
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x += n - 1;
        y += n - 1;

        if (comp[x] != comp[y] || comp[x] == -1 || comp[y] == -1) {
            cout << "-1\n";
        } else {

            int curr = x;
            queue<int> path_q;
            while (parent[curr] != -1) {
                path_q.push(curr);
                curr = parent[curr];
            }

            curr = y;
            stack<int> path_stk;
            while (curr != -1) {
                path_stk.push(curr);
                curr = parent[curr];
            }

            cout << (path_q.size() + path_stk.size()) / 2 + 1 << '\n';

            while (!path_q.empty()) {
                if (path_q.front() >= n) cout << path_q.front() - n + 1 << ' ';
                else cout << path_q.front() + 1 << ' ';
                path_q.pop();
            }
            while (!path_stk.empty()) {
                if (path_stk.top() >= n) cout << path_stk.top() - n + 1 << ' ';
                else cout << path_stk.top() + 1 << ' ';
                path_stk.pop();
            }
            cout << '\n';
        }
    }
}
