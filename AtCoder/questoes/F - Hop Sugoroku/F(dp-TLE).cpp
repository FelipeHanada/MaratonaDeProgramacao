#include <bits/stdc++.h>
using namespace std;

constexpr int md = 998244353;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> dp(n, 0);

    for (int i = n-1; i>=0; i--) {
        dp[i] = 1;
        for (int j=i+a[i]; j<n; j+=a[i]) dp[i] = add(dp[i], dp[j]);
    }

    cout << dp[0] << '\n';
}

/*
consider the suffix problem starting at l
ans(l) = 1 + [ans(i) forall i = l + a[i]k]
*/
