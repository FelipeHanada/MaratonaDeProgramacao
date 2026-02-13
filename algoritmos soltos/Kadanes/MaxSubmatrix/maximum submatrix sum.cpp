#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n+1, vector<ll>(m));
    for (int j=0; j<m; j++) v[0][j] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
            if (i > 0) v[i][j] += v[i-1][j];
        }
    }

    ll best = INT64_MIN;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            ll curr = v[j+1][0] - v[i][0];
            
            for (int k=1; k<m; k++) {
                curr = max(curr + v[j+1][k] - v[i][k], v[j+1][k] - v[i][k]);
                best = max(curr, best);
            }
        }
    }

    cout << best << '\n';
}
