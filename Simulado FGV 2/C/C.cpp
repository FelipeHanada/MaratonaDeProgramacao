#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int md = 123412345;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}


int main() {
    string s, t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    const int B = 256;
    vector<int> hash(n);
    int hasht = t[0];
    hash[0] = s[0];
    int p = 1;
    for (int i=1; i<m; i++) {
        hash[0] = add(mult(hash[0], B), s[i%n]);
        hasht = add(mult(hasht, B), t[i]);
        p = mult(p, B);
    }
    for (int i=1; i<n; i++) {
        hash[i] = sub(hash[i-1], mult(s[i-1], p));
        hash[i] = add(mult(hash[i], B), s[(i+m-1)%n]);
    }

    vector<int> in_deg(n, 0);
    vector<int> next(n, -1);
    for (int i=0; i<n; i++) {
        if (hash[i] == hasht) {
            next[i] = (i + m) % n;
            in_deg[next[i]]++;
        }
    }

    queue<int> q;
    for (int i=0; i<n; i++) if (!in_deg[i]) q.push(i);

    vector<int> dp(n, -1);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        dp[curr] = 0;
        while (next[curr] != -1) {
            dp[next[curr]] = dp[curr] + a[curr];
            curr = next[curr];
        }
    }

    int ans = INT32_MIN;
    for (int i=0; i<n; i++) {
        if (dp[i] == -1) ans = INT32_MAX;
        ans = max(ans, dp[i]);
    }

    if (ans == INT32_MAX) {
        cout << "-1\n"; 
    } else {
        cout << ans << '\n';
    }
}
