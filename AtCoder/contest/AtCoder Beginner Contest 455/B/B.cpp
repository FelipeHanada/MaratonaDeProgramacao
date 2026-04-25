#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i=0; i<h; i++) cin >> grid[i];

    int ans = 0;
    for (int h1 = 0; h1 < h; h1++) {
    for (int h2 = h1 + 1; h2 <= h; h2++) {
    for (int w1 = 0; w1 < w; w1++) {
    for (int w2 = w1 + 1; w2 <= w; w2++) {
        bool ok = 1;
        
        for (int i=h1; ok && i<h2; i++) {
            for (int j=w1; ok && j<w2; j++) {
                ok = grid[i][j] == grid[h1+h2-i-1][w1+w2-j-1];
            }
        }

        ans += ok;
    }}}}

    cout << ans << '\n';
}