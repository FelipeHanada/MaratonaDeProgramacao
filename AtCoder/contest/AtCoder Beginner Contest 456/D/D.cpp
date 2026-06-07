#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(0);

constexpr int md = 998244353;
constexpr int inv2 = (998244353+1)/2;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}


int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> dp(3, 0);
    int ans = 0;
    for (int i=0; i<n; i++) {
        int curr = 1;
        for (int j=0; j<3; j++) {
            if (char(j+'a') == s[i]) continue;
            curr = add(curr, dp[j]);
        }

        dp[s[i]-'a'] = add(dp[s[i]-'a'], curr);
        ans = add(ans, curr);
    }

    cout << ans << '\n';
}
