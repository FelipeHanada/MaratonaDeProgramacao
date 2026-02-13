#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n;
    cin >> n;

    int curr;
    ll prefix = 0;
    ll ans = 0;
    int mod;
    map<ll, int> sums = {{0, 1}};   
    for (int i=0; i<n; i++) {
        cin >> curr;
        prefix += curr;

        mod = (prefix % n + n) % n;
        ans += sums[mod];
        sums[mod]++;
    }

    cout << ans << '\n';
}