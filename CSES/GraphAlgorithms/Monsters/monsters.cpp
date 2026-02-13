#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1000;
char grid[MAX_N][MAX_N];
bool seen[MAX_N][MAX_N];
char ans[MAX_N][MAX_N];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char moves[4] = { 'U', 'D', 'L', 'R' };
map<char, int> movesinv = { {'L', 2}, {'R', 3}, {'U', 0}, {'D', 1} };

int n, m;
bool valid(array<int,2> coord) {
  if (coord[0] < 0 || coord[0] >= n || coord[1] < 0 || coord[1] >= m ||
      seen[coord[0]][coord[1]] || grid[coord[0]][coord[1]] == '#') return false;
  return true;
}

int main() {
  cin >> n >> m;
  vector<array<int,2>> mons;
  array<int,2> a;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'M') {
        mons.push_back({ i, j });
      } else if (grid[i][j] == 'A') {
        a = { i, j };
      }
    }
  }

  for (int i=0; i<n; i++) fill_n(seen[i], m, 0);

  queue<pair<array<int,2>, bool>> bfs;
  for (auto coord : mons) {
    seen[coord[0]][coord[1]] = 1;
    bfs.push({ coord, 0 });
  }
  bfs.push({ a, 1 });
  seen[a[0]][a[1]] = 1;

  array<int,2> exit = { -1, -1 };
  while (!bfs.empty()) {
    auto [ coord, t ] = bfs.front(); bfs.pop();

    if (t == 1 && (coord[0] == 0 || coord[0] == n-1 || coord[1] == 0 || coord[1] == m-1))
        exit = coord;

    for (int i=0; i<4; i++) {
      array<int,2> ncoord = { coord[0] + dx[i], coord[1] + dy[i] };
      if (!valid(ncoord)) continue;
      bfs.push({ ncoord, t });
      seen[ncoord[0]][ncoord[1]] = 1;
      ans[ncoord[0]][ncoord[1]] = moves[i];
    }
  }

  if (exit[0] == -1) {
    cout << "NO\n";
    return 0;
  }
  
  cout << "YES\n";
  stack<char> path;
  while (exit != a) {
    path.push(ans[exit[0]][exit[1]]);
    exit[0] -= dx[movesinv[path.top()]];
    exit[1] -= dy[movesinv[path.top()]];
  }

  cout << path.size() << '\n';
  while (!path.empty()) {
    cout << path.top();
    path.pop();
  }
  cout << '\n';
}

