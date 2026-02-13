#include <bits/stdc++.h>
using namespace std;


#define f first
#define s second

constexpr int MAX_N = 2e5;
int n, m;
string s;
vector<int> adj[MAX_N];

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;

    map<int, pair<pair<int, int>, pair<int, int>>> ans;

    for (int i=0; i<n; i++) if (s[i] == 'D') {

        vector<bool> seen(n, false);
        queue<pair<int, int>> bfs;
        vector<int> dist(n, INT32_MAX);
        multiset<pair<int, int>> small;
        bfs.push({i, 0});
        seen[i] = true;

        while (small.size() < 2) {
            auto [curr, d] = bfs.front();
            bfs.pop();

            for (auto neighbor : adj[curr]) {
                if (seen[neighbor]) continue;
                seen[neighbor] = true;
                if (neighbor < i && s[neighbor] == 'D') {
                    if (ans[neighbor].f.f+d+1 < dist[ans[neighbor].f.s]) {
                        if (dist[ans[neighbor].f.s] < INT32_MAX) small.erase({dist[ans[neighbor].f.s], ans[neighbor].f.s});
                        small.insert({ans[neighbor].f.f+d+1, ans[neighbor].f.s});      
                    }
                    if (ans[neighbor].s.f+d+1 < dist[neighbor]) {
                        if (dist[ans[neighbor].s.s] < INT32_MAX) small.erase({dist[ans[neighbor].s.s], ans[neighbor].s.f});
                        small.insert({ans[neighbor].s.f+d+1, ans[neighbor].s.s});
                    }
                    continue;
                } else {
                    if (s[neighbor] == 'S') small.insert({d + 1, neighbor});
                    bfs.push({neighbor, d + 1});
                }
            }
        }

        ans[i] = {*small.begin(), *(++small.begin())};
    }

    for (auto [x, p] : ans) {
        cout << p.f.f + p.s.f << '\n';
    }
}
