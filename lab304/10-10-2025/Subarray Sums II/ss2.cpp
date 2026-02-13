#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    ll n, x;
    cin >> n >> x;

    ll ans = 0;
    map<ll, int> conta;
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    conta[0] = 1;
    for (int i=0; i<n; i++) {
        cin >> prefix[i+1];
        prefix[i+1] += prefix[i];
        ans += conta[prefix[i+1] - x];
        conta[prefix[i+1]]++;
    }

    cout << ans << '\n';
}