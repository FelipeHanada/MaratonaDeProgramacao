#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n, k;
    cin >> n >> k;

    int xc = k/2;
    auto f = [&](int x, int y) -> int {
        return abs(x - xc) + abs(y - xc);
    };

    vector<vector<int>> seats(k, vector<int>(k, 0));
    vector<vector<int>> ff(k, vector<int>(k+1));
    for (int i=0; i<k; i++) {
        ff[i][0] = 0;
        for (int j=1; j<=k; j++) {
            ff[i][j] = ff[i][j-1] + f(i, j-1);
        }
    }

    while (n--) {
        int x;
        cin >> x;

        vector<array<int,3>> cand;
        for (int i=0; i<k; i++) {
            int qt = 0;
            for (int j=0; j<x; j++) {
                qt += seats[i][j];
            }
            if (!qt) cand.push_back({ff[i][x] - ff[i][0], i, 0});

            for (int j=1; j+x-1 < k; j++) {
                qt -= seats[i][j-1];
                qt += seats[i][j+x-1];
                if (!qt) cand.push_back({ff[i][j+x] - ff[i][j], i, j});
            }
        }

        if (cand.empty()) {
            cout << "-1\n";
        } else {
            sort(cand.begin(), cand.end());
            auto [v, i, j] = cand.front();
            cout << i + 1 << ' ' << j + 1 << ' ' << j + x << '\n';
            for (int y=0; y<x; y++) {
                seats[i][j+y] = 1;
            }
        }
    }
}