#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_M = 1e5;
vector<int> d[MAX_M+1];
void precompute() {
    for (int i=1; i<=MAX_M; i++) {
        for (int j=i; j<=MAX_M; j+=i) {
            d[j].push_back(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int l=0, r=0;
    int prof = 0;
    vector<int> profcnt(m+1, 0);
    int ans = INT32_MAX;
    while (l < n) {
        while (r < n && prof < m) {
            int curr = a[r++];
            for (int i=0; i<d[curr].size() && d[curr][i] <= m; i++) {
                if ((profcnt[d[curr][i]]++) == 0) prof++;
            }
        }

        if (prof == m) {
            ans = min(ans, a[r-1] - a[l]);

            int curr = a[l++];
            for (int i=0; i<d[curr].size() && d[curr][i] <= m; i++) {
                if ((--profcnt[d[curr][i]]) == 0) prof--;
            }
        } else {
            break;
        }
    }

    if (ans == INT32_MAX) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
}


int main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
