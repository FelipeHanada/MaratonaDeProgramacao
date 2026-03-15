#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;



int main() { _
    int n;
    cin >> n;
    vector<array<int,2>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    auto solve = [&]() -> ll {
        sort(a.begin(), a.end());
        queue<vector<int>> q;
        for (int i=0; i<n; i++) {
            if (q.empty() || a[q.back()[0]][0] != a[i][0]) {
                q.push(vector<int>());
            }
            q.back().push_back(i);
        }

        ll ans = INT64_MAX;
        vector<int> last = q.front(); q.pop();
        array<ll,2> dp = { a[last.back()][1] - a[last.front()][1], a[last.back()][1] - a[last.front()][1] };
        while (q.empty()) {
            int dx = (a[q.front()[0]][0] - a[last[0]][0]);
            dp = {
                dp[0] + 
            }
        }

    };
}
