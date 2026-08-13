#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> next(n);
    for (int i=0; i<n; i++) {
        cin >> next[i]; next[i]--;
    }

    vector<int> in_deg(n, 0);
    for (int i=0; i<n; i++) in_deg[next[i]]++;

    int curr_group_id = 0;
    vector<pair<int, int>> id(n, { -1, -1 });
    vector<pair<int, int>> next_group;
    vector<int> group_size;
    for (int tail=0; tail<n; tail++) if (!in_deg[tail]) {
        int curr = tail;
        int dist = 0;
        while (id[curr].first == -1) {
            id[curr] = { curr_group_id, dist++ };
            curr = next[curr];
        }
        curr_group_id++;

        if (id[curr].first == id[tail].first) {
            // new cycle found
            int dist2 = 0;
            int curr2 = curr;
            do {
                id[curr2] = { curr_group_id, dist2++ };
                curr2 = next[curr2];
            } while (curr2 != curr);
            
            next_group.push_back({ curr_group_id, curr });
            group_size.push_back(dist - dist2);

            next_group.push_back({ curr_group_id, curr });
            group_size.push_back(dist2);
            curr_group_id++;
        } else {
            next_group.push_back({ id[curr].first, curr });
            group_size.push_back(dist);
        }
    }

    for (int i=0; i<n; i++) if (id[i].first == -1) {
        // ciclos soltos
        int dist = 0;
        int curr = i;
        do {
            id[curr] = { curr_group_id, dist++ };
            curr = next[curr];
        } while (curr != i);

        next_group.push_back({ curr_group_id, curr });
        group_size.push_back(dist);
        curr_group_id++;
    }

    while (k--) {
        int a, b; cin >> a >> b; a--; b--;

        int ans = 0;
        if (id[a].first != id[b].first) {
            if (next_group[id[a].first].first != id[b].first) {
                cout << "-1\n";
                continue;
            }

            ans = group_size[id[a].first] - id[a].second;
            a = next_group[id[a].first].second;
        }

        int group_id = id[a].first;
        if (next_group[group_id].first == group_id) { // cycle
            ans += (id[b].second - id[a].second + group_size[group_id]) % group_size[group_id];
        } else { // path
            if (id[a].second > id[b].second) {
                cout << "-1\n";
                continue;
            }

            ans += id[b].second - id[a].second;
        }

        cout << ans << '\n';
    }
}
