#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_T = 1000;
constexpr int MAX_N = 1000;
int N, M, C;
int m[MAX_N];
vector<int> adj[MAX_N];
int dp[MAX_T + 1][MAX_N];
// dp[t][i] max money you can get after t travels ending on the i city

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    cin >> N >> M >> C;

    for (int i=0; i<N; i++) {
        cin >> m[i];
    }

    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }

    for (int t=0; t<MAX_T+1; t++) fill_n(dp[t], N, -1);
    dp[0][0] = 0;

    int ans = INT32_MIN;
    for (int t=0; t<MAX_T; t++) {
        for (int i=0; i<N; i++) {
            if (dp[t][i] == -1) continue;
            //  this city could not be visited

            for (int x : adj[i]) {
                dp[t + 1][x] = max(dp[t + 1][x], dp[t][i] + m[x]);
            }
        }

        ans = max(ans, dp[t + 1][0] - C * (t + 1) * (t + 1));
    }

    cout << ans << endl;
}