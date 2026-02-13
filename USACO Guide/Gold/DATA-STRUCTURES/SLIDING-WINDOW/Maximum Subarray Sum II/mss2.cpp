#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 2e5;
ll prefix[MAX_N+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    
    prefix[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
    }

    // we test the best sum for a subarray starting in i
    // we know that the best sum should end in the biggest prefix[i+1+length]
    // where length is restrained by a and b
    // then, let i be any value, we want to find the biggest value of prefix in [i+1+a, i+1+b] range

    ll ans = INT64_MIN;
    multiset<ll> ms;
    for (int i=a; i<=b; i++) {
        ms.insert(prefix[i]);
    }
    
    for (int i=0; i+a<=n; i++) {
        ans = max(ans, *ms.rbegin() - prefix[i]);

        if (i+b+1 <= n) ms.insert(prefix[i+b+1]);
        ms.extract(prefix[i+a]);
    }

    cout << ans << '\n';
}
