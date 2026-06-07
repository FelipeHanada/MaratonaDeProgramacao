#include <bits/stdc++.h>
using namespace std;


/*
a quantidade de células permitidas é limitada por O(10^5)
o que torna construir o grafo das células permitidas feasible
já que a quantidade de arestas também é limitada por O(4 * 10^5)
*/

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    map<pair<int,int>, vector<pair<int,int>>> adj;
    for (int i=0; i<n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int i=a; i<=b; i++) adj[{r, i}];

        for (int i=a; i<=b; i++) {
            for (int dx=-1; dx<=1; dx++) {
                for (int dy=-1; dy<=1; dy++) if (dx != 0 || dy != 0) {
                    if (adj.count({r+dy, i+dx})) {
                        adj[{r, i}].push_back({r+dy, i+dx});
                        adj[{r+dy, i+dx}].push_back({r, i});
                    }                    
                }
            }
        }
    }

    queue<pair<pair<int, int>, int>> bfs;
    bfs.push({{x1, y1}, 0});
    set<pair<int,int>> seen; seen.insert({x1,y1});
    int ans = -1;
    while (!bfs.empty() && ans == -1) {
        auto [curr, d] = bfs.front(); bfs.pop();
        if (curr.first == x2 && curr.second == y2) {
            ans = d;
            break;
        }

        for (auto neighbor : adj[curr]) {
            if (seen.count(neighbor)) continue;
            seen.insert(neighbor);
            bfs.push({neighbor, d+1});
        }
    }

    cout << ans << '\n';
}
