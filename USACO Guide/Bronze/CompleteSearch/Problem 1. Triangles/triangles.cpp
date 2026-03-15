#include <bits/stdc++.h>
using namespace std;


int main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n;
  cin >> n;
  vector<array<int,2>> p(n);
  for (int i=0; i<n; i++) {
    cin >> p[i][0] >> p[i][1];
  }

  int ans = 0;
  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      for (int k=j+1; k<n; k++) {
        set<int> xs, ys;
        xs.insert(p[i][0]);
        xs.insert(p[j][0]);
        xs.insert(p[k][0]);
        if (xs.size() != 2) continue;

        ys.insert(p[i][1]);
        ys.insert(p[j][1]);
        ys.insert(p[k][1]);
        if (ys.size() != 2) continue;

        int x = p[i][0]+p[j][0]+p[k][0]-min(p[i][0],min(p[j][0],p[k][0]))-max(p[i][0],max(p[j][0],p[k][0]));
        int X = p[i][0]+p[j][0]+p[k][0]-2*x;
        int y = p[i][1]+p[j][1]+p[k][1]-min(p[i][1],min(p[j][1],p[k][1]))-max(p[i][1],max(p[j][1],p[k][1]));
        int Y = p[i][1]+p[j][1]+p[k][1]-2*y;

        ans = max(ans, abs(x-X)*abs(y-Y));
      }
    }
  }

  cout << ans << '\n';
}
