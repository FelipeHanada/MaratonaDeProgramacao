#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n, set<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    set<int> unseen;
    for (int i=0; i<n; i++) unseen.insert(i);
    map<int, int> coloring;
    bool valid = true;
    while (unseen.size() > 0 && valid) {
        stack<int> dfs;
        dfs.emplace(*unseen.begin());
        coloring.insert({*unseen.begin(), 1});

        while (dfs.size() > 0 && valid) {
            int start = dfs.top();
            dfs.pop();
            unseen.erase(start);
            int color = (coloring[start] == 1) ? 2 : 1;

            for (auto x : adj[start]) {
                if (coloring.find(x) != coloring.end()) {
                    // checks if coloring is ok
                    if (coloring[x] != color) {
                        valid = false;
                        break;
                    }
                } else {
                    dfs.emplace(x);
                    coloring.insert({x, color});
                }
            }
        }
    }

    if (valid) {
        for (auto x : coloring) {
            cout << x.second << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
