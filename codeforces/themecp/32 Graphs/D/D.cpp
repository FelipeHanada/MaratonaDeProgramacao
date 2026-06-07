#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

bool comp2(array<int,2> a, array<int,2> b) {
    swap(a[0], a[1]);
    swap(b[0], b[1]);
    return a < b;
}

int main() { _
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    map<int, vector<array<int,2>>> a;
    for (int i=0; i<n; i++) {
        int r, x, y;
        cin >> r >> x >> y;
        a[r].push_back(array<int,2>({x, y}));
    }

    map<int, vector<array<int,2>>> b;
    for (auto [row, ranges] : a) {
        vector<array<int,2>> sorted = ranges;
        vector<array<int,2>> novo;
        sort(sorted.begin(), sorted.end());

        int l = sorted[0][0], r = sorted[0][1];
        for (int i=1; i<sorted.size(); i++) {
            if (sorted[i][0] <= l + 1) r = max(r, sorted[i][1]);
            else {
                novo.push_back(array<int,2>({l, r}));
                l = sorted[i][0];
                r = sorted[i][1];
            }
        }
        novo.push_back(array<int,2>({l, r}));
        b[row] = novo;
    }

    map<int, vector<array<int,2>>> adj;
    for (auto [r, ranges] : b) {
        adj[r].assign(ranges.size(), array<int,2>({-1, -1}));

        for (auto [l, r] : ranges) {
            auto ubL = upper_bound(b[r+1].begin(), b[r+1].end(), array<int,2>({l, 0}));
            auto ubR = upper_bound(b[r+1].begin(), b[r+1].end(), array<int,2>({0, r}), comp2);
        }
    }
}
