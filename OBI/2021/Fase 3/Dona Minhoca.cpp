#include <bits/stdc++.h>
using namespace std;


using ll = long long;


int n;
vector<vector<int>> adj;
array<int,4> dfs(int i, int parent, int depth) {
    /* 
    {
        height of this subtree,
        number of nodes on the lowest level,
        size of the max cycle in this subtree,
        number of cycles of that size
    }
    */

    if (adj[i].size() == 1 && parent != -1) {
        return { 1, 1, -1, 0 };
    }

    int h = -1, nlow = 0, scycle = -1, ncycle = 0;
    vector<pair<int, int>> a;
    for (int neighbor : adj[i]) {
        if (neighbor == parent) continue;
        auto [ hh, nloww, scyclee, ncyclee ] = dfs(neighbor, parent, depth + 1);

        if (hh < h) {
            h = hh + 1;
            nlow = nloww;
        } else if (hh == h) {
            nlow += nloww;
        }

        if (scyclee > scycle) {
            scycle = scyclee;
            ncycle = ncyclee;
        } else if (scyclee == scycle) {
            ncycle += ncyclee;
        }

        a.push_back({ hh, nloww });
    }
    h++;
    sort(a.rbegin(), a.rend());

    if (a.size() == 1) {
        return { h, nlow, scycle, ncycle };
    } else {
        if (a[0].first == a[1].first) {
            int q = 0;
            int ncycle = 0;
            for (auto [ hh, nloww ] : a) {
                if (hh < h - 1) break;
                q += nloww;
            }
        } else {

        }
    }
}

int main() {
    cin >> n;
    adj.assign(n, vector<int>());
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // each cycle is caracterized by the edge that is added
    // we need to check each edge possible?
    // no, we can check only edges that connect two leafs
    // we need to check each pair of leaves?
    // no, we only need to check the leaves with maximum depth

}