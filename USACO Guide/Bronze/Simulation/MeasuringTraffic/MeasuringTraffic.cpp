#include <bits/stdc++.h>
using namespace std;


pair<int, int> solve(vector<tuple<int, int, int>> &e) {
    int lb = 0, ub = 0;
    int slb = 0, sub = INT32_MAX;

    int a, b;
    for (auto it = e.begin(); it != e.end(); it++) {
        a = get<1>(*it);
        b = get<2>(*it);
        switch (get<0>(*it)) {
            case 0:
                slb = max(slb, a - ub);
                sub = min(sub, b - lb);
                break;
            case 1:
                lb += a;
                ub += b;
                break;
            case 2:
                lb -= b;
                ub -= a;
                break;
        }
    }

    return {slb, sub};
}

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> e;
    vector<tuple<int, int, int>> er;
    string s;
    int a, b;
    for (int i=0; i<n; i++) {
        cin >> s >> a >> b;
        if (s.compare("none") == 0) {
            e.push_back({0, a, b});
            er.insert(er.begin(), {0, a, b});
        } else if (s.compare("on") == 0) {
            e.push_back({1, a, b});
            er.insert(er.begin(), {2, a, b});
        } else {
            e.push_back({2, a, b});
            er.insert(er.begin(), {1, a, b});
        }
    }

    pair<int, int> start = solve(e);
    pair<int, int> end = solve(er);

    cout << start.first << " " << start.second << "\n";
    cout << end.first << " " << end.second << "\n";
}
