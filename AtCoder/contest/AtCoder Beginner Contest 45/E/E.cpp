#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

char m[] = {'L', 'R', 'D', 'U'};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string path;
bool seen[1000][1000];
int n, a, b;

inline bool valid(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}
bool solve(int x, int y) {
    if (path.size() ==  n*n-2) return 1;
    if (x == n-1 && y == n-1) return 0;

    for (int i=0; i<4; i++) {
        if (valid(x+dx[i], y+dy[i]) && !seen[x+dx[i]][y+dy[i]]) {
            path.push_back(m[i]);
            seen[x+dx[i]][y+dy[i]] = 1;
    
            if (solve(x+dx[i], y+dy[i])) {
                return true;
            }
    
            seen[x+dx[i]][y+dy[i]] = 0;
            path.pop_back();
        }
    }

    return 0;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> a >> b;
        
        for (int i=0; i<n; i++)
        fill_n(seen[i], n, 0);
        
        seen[0][0] = seen[a-1][b-1] = 1;
        path.clear();
        if (solve(0, 0)) {
            cout << "Yes\n";
            cout << path << '\n';
        } else {
            cout << "No\n";
        }

    }
}
