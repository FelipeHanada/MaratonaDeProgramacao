#include <bits/stdc++.h>
using namespace std;

int h, w;
pair<int, int> pos;
vector<pair<int, int>> trash;
pair<int, int> moves[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


int check(int offset_i, int offset_j, const set<int>& t, set<int>& inside) {
    // -1 invalid, 0 not completed, 1 completed
    inside.clear();
    set<int> outside;
    bool ok = true;
    for (auto i : t) {
        pair<int, int> p = make_pair(trash[i].first + offset_i, trash[i].second + offset_j);
        if (p.first >= 0 && p.first < h && p.second >= 0 && p.second < w) {
            inside.insert(i);
        }
        if (p == pos) ok = false;
    }

    if (!ok) return -1;
    if (!inside.empty()) return 0;
    return 1;
}

int main() {
    trash.clear();
    cin >> h >> w;
    for (int i=0; i<h; i++) {
        string s;
        cin >> s;
        for (int j=0; j<w; j++) {
            if (s[j] == '#') {
                trash.push_back({i, j});
            } else if (s[j] == 'T') {
                pos = make_pair(i, j);
            }
        }
    }

    set<pair<int, int>> seen;
    queue<tuple<int, int, int, set<int>>> bfs;
    // steps, offset (i, j), trashes
    seen.insert({0, 0});
    bfs.push({0, 0, 0, set<int>()});
    for (int i=0; i<trash.size(); i++) get<3>(bfs.front()).insert(i);
    int ans = -1;
    while (!bfs.empty() && ans == -1) {
        auto [d, i, j, t] = bfs.front(); bfs.pop();

        for (int m=0; m<4; m++) {
            pair<int, int> curr = {i + moves[m].first, j + moves[m].second};
            if (seen.count(curr)) continue;
            seen.insert(curr);
            set<int> t2;
            int res = check(curr.first, curr.second, t, t2);
            if (res == -1) continue;
            if (res == 1) {
                ans = d+1;
                break;
            }

            bfs.push({d+1, curr.first, curr.second, t2});
        }
    }

    cout << ans << '\n';
}
