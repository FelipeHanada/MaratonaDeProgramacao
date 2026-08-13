#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
constexpr int md = 998244353;
inline int add(int a, int b) { a += b; if (a >= md) a -= md; return a; }
inline int sub(int a, int b) { a -= b; if (a < 0) a += md; return a; }
inline int mult(int a, int b) { return ((ll)a * b) % md; }


int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) cin >> a[i];


    vector<string> b = a;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (a[i][j] == '#') {
        bool safe = 0;
        for (int k=0; k<8; k++) {
            int ii = i + dx[k], jj = j + dy[k];
            if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
            if (a[ii][jj] == '.') safe = 1;
        }

        if (!safe) b[i][j] = '.';
    }
    a = b;


    vector<string> ans = a;
    queue<array<int,3>> q;
    set<pair<int,int>> seen;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (a[i][j] == '#') {
        q.push({ i, j, 0 });
        seen.insert({ i, j });
    }

    while (!q.empty()) {
        auto [i, j, t] = q.front(); q.pop();
        if (t % 2) ans[i][j] = '.';
        else ans[i][j] = '#';

        for (int k=0; k<8; k++) {
            int ii = i + dx[k], jj = j + dy[k];
            if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
            if (seen.count({ ii, jj })) continue;
            seen.insert({ ii, jj });
            q.push({ ii, jj, t + 1 });
        }
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] << '\n';
    }
}
