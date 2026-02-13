#include <bits/stdc++.h>
using namespace std;


pair<int, int> moves[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main() {
    int h, w;
    cin >> h >> w;
    char c;
    pair<int, int> T;
    vector<pair<int, int>> trashes;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> c;
            if (c == '#') {
                trashes.push_back({i, j});
            } else if (c == 'T') {
                T = {i, j};
            }
        }
    }

    set<tuple<int, int, int, int, int, int>> seen;
    queue<tuple<int, int, int, int, int, int, int>> bfs;
    bfs.push({0, 0, 0, 0, 0, h, w});
    seen.insert({0, 0, 0, 0, h, w});
    while (!bfs.empty()) {
        auto [d, y, x, t, l, b, r] = bfs.front();
        bfs.pop();

        bool ok = true;
        int c = 0;
        for (auto [ty, tx] : trashes) {
            if (ty < t || ty >= b || tx < l || tx >= r) continue;
            if (make_pair(ty + y, tx + x) == T) {
                ok = false;
            }
            c++;
        }

        if (!ok) continue;
        if (c == 0) {
            cout << d << '\n';
            return 0;
        }

        for (int i=0; i<4; i++) {
            int new_y = y+moves[i].first,
                new_x = x+moves[i].second,
                new_t = max(t, t - moves[i].first),
                new_l = max(l, l - moves[i].second),
                new_b = min(b, b - moves[i].first),
                new_r = min(r, r - moves[i].second);
            if (seen.count({new_y, new_x, new_t, new_l, new_b, new_r})) continue;
            seen.insert({new_y, new_x, new_t, new_l, new_b, new_r});
            bfs.push({d+1, new_y, new_x, new_t, new_l, new_b, new_r});
        }
    }

    cout << "-1\n";
}
