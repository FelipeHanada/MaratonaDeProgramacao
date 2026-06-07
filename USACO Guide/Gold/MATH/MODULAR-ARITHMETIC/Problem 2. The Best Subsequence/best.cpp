#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> intervals;
    while (m--) {
        int l, r; cin >> l >> r;
        intervals.push_back({ l, -r });
    }
    map<int, int> black;
    sort(intervals.begin(), intervals.end());
    pair<int, int> curr = { intervals[0].first, -intervals[0].second };
    for (int i=1; i<intervals.size(); i++) {
        auto [l, rr] = intervals[i];
        int r = -rr;
        if (l > curr.second + 1) {
            black[curr.second] = curr.first;
        } else {
            curr.second = r;
        }
    }
    black[curr.second] = curr.first;

    while (q--) {

    }
}

/*
its always optimal to make all the 1's into the prefix
    and take the rest of the zeros (after the last 1) as a suffix

the problem is to track the last 1

*/