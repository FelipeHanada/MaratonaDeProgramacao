#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int n;
vector<int> a;
vector<int> height;
vector<ll> sum;
vector<vector<int>> adj;
vector<ll> dp0, dp1;
void dfs(int i, int p) {
    sum[i] = a[i];
    int big1 = -1, big2 = -1;
    for (int j : adj[i]) if (j != p) {
        dfs(j, i);
        sum[i] += sum[j];
        height[i] = max(height[i], height[j] + 1);

        if (big1 == -1 || height[j] > height[big1]) {
            big2 = big1;
            big1 = j;
        } else if (big2 == -1 || height[j] > height[big2]) {
            big2 = j;
        }
    }

    if (big1 == -1) {
        // no children
        dp0[i] = dp1[i] = 0;
    } else if (big2 == -1) {
        // one children
        dp0[i] = dp0[big1] + sum[big1];
        dp1[i] = dp1[big1] + sum[big1];
    } else {
        // atleast two children
        dp0[i] = 0;
        for (int j : adj[i]) if (j != p) {
            dp0[i] += dp0[j] + sum[j];
        }

        dp1[i] = dp0[i];
        for (int j : adj[i]) if (j != p) {
            dp1[i] = max(dp1[i], dp0[i] - dp0[j] + dp1[j]);

            int h;
            if (j == big1) h = height[big2];
            else h = height[big1];
            dp1[i] = max(dp1[i], dp0[i] + (h + 1) * sum[j]);
        }
    }
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];
    adj.assign(n, vector<int>());
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    sum.assign(n, 0);
    height.assign(n, 0);
    dp0.resize(n);
    dp1.resize(n);
    dfs(0, -1);

    for (int i=0; i<n; i++) cout << dp1[i] << ' ';
    cout << '\n'; 
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
}
