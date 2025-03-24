#include <bits/stdc++.h>
using namespace std;


pair<int, int> h[1000];
pair<int, int> g[1000];
int dp[1001][1001];
//  dp[i][j] = minimum amount of energy required to reach Hi after going through G1...Gj

int cost(pair<int, int> &a, pair<int, int> &b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

int main() {
    int H, G;
    cin >> H >> G;

    for (int i=0; i<H; i++)
        cin >> h[i].first >> h[i].second;
    for (int i=0; i<G; i++)
        cin >> g[i].first >> g[i].second;

    for (int i=0; i<=H; i++)
        fill_n(dp[i], G + 1, 0);

    for (int j=0; j<=G; j++)
        dp[0][j] = dp[1][j] = INT32_MAX >> 1;
    dp[1][0] = 0;

    for (int i=2; i<=H; i++)
        dp[i][0] = dp[i-1][0] + cost(h[i-1], h[i]);

    for (int i=2; i<=H; i++) {
        for (int j=1; j<=G; j++) {
            
        }
    }
}
