#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> black(n+1, vector(n+1, 0));
    vector<vector<int>> white(n+1, vector(n+1, 0));

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c == '.') white[i][j]++;
            else black[i][j]++;

            white[i][j] += white[i-1][j] + white[i][j-1] - white[i-1][j-1];
            black[i][j] += black[i-1][j] + black[i][j-1] - black[i-1][j-1];
        }
    }

    int best = INT32_MAX;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            best = min(best, black[i][j] + white[n][n] - white[i][j]);
        }
    }
    cout << best << '\n';
}