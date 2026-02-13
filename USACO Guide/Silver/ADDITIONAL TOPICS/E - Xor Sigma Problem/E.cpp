#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 2e5;
int n;
int a[MAX_N];
int prefix[MAX_N+1];

int main() {
    cin >> n;
    prefix[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i-1];
        prefix[i] = a[i-1] ^ prefix[i-1];
    }

    ll ans = 0;
    for (int i=0; i<27; i++) {
        pair<int, int> dp = {0, 0}; // subarrays com quantidade par/ímpar de 1's e terminam no atual

        ll count = 0;
        for (int j=0; j<n; j++) {
            if (a[j] & (1 << i)) {
                dp = make_pair(dp.second, dp.first+1);
                count--; // removendo 1's solitários
            } else {
                dp.first++;
            }

            count += dp.second;
        }

        ans += (count << i);        
    }

    cout << ans << '\n';
}
