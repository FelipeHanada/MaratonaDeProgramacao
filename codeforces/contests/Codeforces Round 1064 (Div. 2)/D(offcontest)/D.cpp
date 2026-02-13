#include <bits/stdc++.h>
using namespace std;


/*
for each generated set S
    for all x not in S, we should be able to "hide" x
        inside the partitions that generated S
    for each y in S, we can "hide" at most cnt(y) equal elements
    thus, for any generated set S, the following inequality must be satisfied:
        max_{x not in S} cnt(x) <= sum_{y in S} cnt(y)


Let X be such that cnt(X) = max cnt
    I) suppose X not in S, then sum_{y in S} cnt(y) >= max cnt
    II) suppose X in S, satisfy the constraint

The problem, then, reduces to find the number of sets that satisfy
    sum_{y in S} cnt(y) >= max cnt
*/

#define ll long long
constexpr int MOD = 998244353;


void solve() {
    int n;
    cin >> n;
    map<int, int> ms;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        ms[x]++;
    }
    vector<int> cnt;
    int max_cnt = 0;
    for (auto &[p, q] : ms) {
        cnt.push_back(q);
        max_cnt = max(max_cnt, q);
    }


    vector<int> dp(n+1, 0);
    // dp[i] = number of generated multisets such that sum_{y in S} cnt(y) = i
    dp[0] = 1;
    for (int i=0; i<cnt.size(); i++) {
        for (int j=n; j>=cnt[i]; j--) {
            dp[j] = (dp[j] + ((ll)dp[j-cnt[i]]*cnt[i]) % MOD) % MOD;
        }
    }

    int ans = 0;
    for (int i=max_cnt; i<=n; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
