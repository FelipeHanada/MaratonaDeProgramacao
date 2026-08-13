#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> color(n, 0);
    vector<int> dp(n, -1);
    for (int i=0; i<n; i++) if (color[i] == 0) {
        stack<int> stk;
        stk.push(i);

        int cycle_start = -1;
        while (!stk.empty()) {
            auto curr = stk.top(); stk.pop();

            if (color[curr] == 0) {
                color[curr] = 1;
                stk.push(curr);

                if (color[a[curr]] == 0) {
                    stk.push(a[curr]);
                } else if (color[a[curr]] == 1) {
                    cycle_start = a[curr];
                }

            } else {
                color[curr] = 2;

                if (curr == cycle_start) {
                    int size = 1;
                    for (int j = a[curr]; curr != j; j = a[j]) size++;

                    dp[curr] = size;
                    for (int j = a[curr]; curr != j; j = a[j]) dp[j] = size;
                } else {
                    dp[curr] = dp[a[curr]] + 1;
                }
            }
        }
    }


    ll ans = 0;
    for (int i=0; i<n; i++) ans += dp[i];
    cout << ans << '\n';
}