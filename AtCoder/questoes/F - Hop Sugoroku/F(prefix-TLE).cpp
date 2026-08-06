#include <bits/stdc++.h>
using namespace std;


constexpr int md = 998244353;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    map<pair<int, int>, int> s;
    vector<int> dp(n, 1);
    for (int i=n-1; i>=0; i--) {
        if (a[i] < n)
            dp[i] = add(dp[i], s[{a[i], i % a[i]}]);

        for (int j=1; j<n; j++) {
            s[{j, i % j}] = add(s[{j, i % j}], dp[i]);
        }
    }

    cout << dp[0] << '\n';
}


/*
consider the suffix problem starting at l
ans(l) = 1 + [ ans(i) forall i = l + a[i]k ]


lets 
*/

