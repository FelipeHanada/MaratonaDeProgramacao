#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
vector<vector<int>> a;
inline bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int main() {
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    auto solve = [&](int i, int j) -> ll {
        priority_queue<array<int, 3>> pq;
        vector<vector<bool>> seen(n, vector<bool>(m, 0));
        seen[i][j] = 1;
        for (int k=0; k<4; k++) {
            int ii = i + dx[k], jj = j + dy[k];
            if (valid(ii, jj) && !seen[ii][jj]) {
                seen[ii][jj] = 1;
                pq.push({ -a[ii][jj], ii, jj });
            }
        }

        ll power = a[i][j];
        while (!pq.empty()) {
            auto [ _, ii, jj ] = pq.top(); pq.pop();
            if (power < a[ii][jj]) break;

            power += a[ii][jj];

            for (int k=0; k<4; k++) {
                int iii = ii + dx[k], jjj = jj + dy[k];
                if (!valid(iii, jjj) || seen[iii][jjj]) continue;

                seen[iii][jjj] = 1;
                pq.push({ -a[iii][jjj], iii, jjj });
            }
        }

        return power;
    };


    vector<vector<ll>> ans(n, vector<ll>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ans[i][j] = solve(i, j);
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}