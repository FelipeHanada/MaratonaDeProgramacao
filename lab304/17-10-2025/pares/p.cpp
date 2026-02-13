#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<vector<int>> rank(n, vector<int>(k));
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            int id;
            cin >> id;
            rank[id-1][i] = j;
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            bool consistent = true;
            for (int x=1; consistent && x<k; x++) {
                if ((rank[i][x] - rank[j][x]) * (rank[i][x-1] - rank[j][x-1]) < 0) {
                    consistent = false;
                }
            }
            if (consistent) ans++;
        }
    }

    cout << ans << '\n';
}