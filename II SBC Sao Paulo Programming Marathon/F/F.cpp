#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second


int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> points(n);
    for (int i=0; i<n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    vector<vector<tuple<float, int, int>>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back({ atan2(points[y].f - points[x].f, points[y].s - points[x].s), y, 2*i });
        adj[y].push_back({ atan2(points[x].f - points[y].f, points[x].s - points[y].s), x, 2*i+1 });
    }
    for (int i=0; i<n; i++) sort(adj[i].begin(), adj[i].end());

    vector<int> he_next(2*m), he_start(2*m), he_end(2*m);
    for (int i=0; i<n; i++) {
        for (auto [ _, j, id ] : adj[i]) {
            he_start[id] = i;
            he_end[id] = j;

            int next_idx = 0;
            int rev_id = id ^ 1;
            while (next_idx < adj[j].size() && get<2>(adj[j][next_idx]) != rev_id) next_idx++;

            he_next[id] = get<2>(adj[j][(next_idx + 1) % adj[j].size()]);
        }
    }

    vector<vector<pair<int, int>>> faces;
    vector<bool> seen(2*m, 0);
    for (int i=0; i<2*m; i++) if (!seen[i]) {
        vector<pair<int, int>> face;
        int curr = i;
        int area2 = 0;
        do {
            seen[curr] = 1;
            face.push_back(points[he_start[curr]]);
            int x1 = points[he_start[curr]].f,
                y1 = points[he_start[curr]].s,
                x2 = points[he_end[curr]].f,
                y2 = points[he_end[curr]].s;
            area2 += x1*y2 - x2*y1;
            curr = he_next[curr];
        } while (curr != i);

        if (area2 > 0) faces.push_back(face);
    }

    string ans;
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;

        bool ok = 1;
        for (auto face : faces) {
            int cnt = 0;
            for (int i=0; i<face.size(); i++) {
                int j = (i + 1) % face.size();
                if (y < min(face[i].s, face[j].s) || y > max(face[i].s, face[j].s)) continue;
                float k = (y - points[j].s)/float(points[i].s - points[j].s);
                float xx = points[i].f * k + points[j].f * (1 - k);
                if (xx < x) continue;
                cnt++;
            }

            if (cnt & 1) {
                ok = 0;
                break;
            }
        }

        ans += "PG"[ok];
    }
    
    cout << ans << '\n';
}