#include <bits/stdc++.h>
using namespace std;


struct Hash {
    size_t operator()(const pair<int, int>& p) const {
        return ((size_t) p.first << 32) + p.second;
    }
};

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int n, m, p, q; char x;
    cin >> n >> m;
    unordered_set<pair<int, int>, Hash> a, b;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> x;
            if (x != '0') a.insert({i, j});
        }
    }

    cin >> p >> q;
    for (int i=0; i<p; i++) {
        for (int j=0; j<q; j++) {
            cin >> x;
            if (x != '0') b.insert({i, j});
        }
    }

    pair<int, pair<int, int>> best = {0, {0, 0}};
    for (int x=-n+1; x<p; x++) {
        for (int y=-m+1; y<q; y++) {
            int curr = 0;
            for (auto [i, j] : a) {
                if (b.count({i+x, j+y})) curr++;
            }

            best = max(best, {curr, {x, y}});
        }
    }

    cout << best.second.first << ' ' << best.second.second << '\n';
}
