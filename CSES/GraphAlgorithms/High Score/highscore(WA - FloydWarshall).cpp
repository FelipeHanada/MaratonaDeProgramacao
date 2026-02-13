#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr ll NOEDGE = INT64_MIN;
constexpr ll INF = INT64_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<ll>> adj(n, vector<ll>(n, NOEDGE));
  vector<vector<ll>> fw(n, vector<ll>(n, NOEDGE));
  for (int i=0; i<m; i++) {
    int a, b, x;
    cin >> a >> b >> x;
    a--; b--;
    adj[a][b] = x;
    fw[a][b] = x;
  }

  for (int k=0; k<n; k++) {
    for (int i=0; i<n; i++) if (fw[i][k] != NOEDGE) {
      for (int j=0; j<n; j++) if (fw[k][j] != NOEDGE) {
        if (fw[i][k] == INF || fw[k][j] == INF) {
          fw[i][j] = INF;
          continue;
        }

        fw[i][j] = max(fw[i][j], fw[i][k] + fw[k][j]);
        if (fw[j][i] != NOEDGE) {
          if (fw[i][k] + fw[k][j] + fw[j][i] > 0)
            fw[i][k] = fw[k][j] = fw[j][i] = INF;
        }
      }
    }
  }

  if (fw[0][n-1] == INF) {
    cout << "-1\n";
  } else {
    cout << fw[0][n-1] << '\n';
  }
}
