#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<array<ll,3>> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }

        vector<vector<int>> adj1(n), adj2(n);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                ll da = a[i][0] - a[j][0],
                    db = a[i][1] - a[j][1],
                    dc = a[i][2] - a[j][2];

                if (da == 0) {
                    if (db == 0) {
                        if (dc > 0) { // f[i] > f[j]
                            adj1[i].push_back(j);
                            adj2[j].push_back(i);
                        } else if (dc < 0) {
                            adj1[j].push_back(i);
                            adj2[i].push_back(j);
                        }
                    }
                } else {
                    ll delta = db*db - 4*da*dc;

                    if (da > 0 && ((delta > 0 && da < 0) || (delta < 0 && da > 0))) {
                        adj1[i].push_back(j);
                        adj2[j].push_back(i);
                    } else if (da < 0 && ((delta > 0 && da > 0) || (delta < 0 && da < 0))) {
                        adj1[j].push_back(i);
                        adj2[i].push_back(j);
                    }
                }
            }
        }

        vector<int> dp1(n, 0), dp2(n, 0);
        vector<int> in_deg(n, 0);
        queue<int> q;
        for (int i=0; i<n; i++) {
            for (int next : adj1[i]) in_deg[next]++;
        }
        for (int i=0; i<n; i++) if (in_deg[i] == 0) q.push(i);
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            dp1[curr]++;
            for (int next : adj1[curr]) {
                if (--in_deg[next] == 0) q.push(next);
                dp1[next] = max(dp1[next], dp1[curr]);
            }
        }

        for (int i=0; i<n; i++) {
            for (int next : adj2[i]) in_deg[next]++;
        }
        for (int i=0; i<n; i++) if (in_deg[i] == 0) q.push(i);
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            dp2[curr]++;
            for (int next : adj2[curr]) {
                if (--in_deg[next] == 0) q.push(next);
                dp2[next] = max(dp2[next], dp2[curr]);
            }
        }


        for (int i=0; i<n; i++) {
            cout << dp1[i] + dp2[i] - 1 << ' ';
        }
        cout << '\n';
    }
}
