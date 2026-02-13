#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_M = 2e5;
ll n, m, a, b;
ll s[MAX_M];
bool check(ll x) {
    // is it possible to light x firecrackers?
    if (x == 0) return true;
    if (x > b-a-1 || x > m) return false;

    // after we light x firecrackers
    // the obvious strategy is to run all the way to the left
    // and lit the rest of the firecrackers
    // it is not possible, we will have to go right

    // we need a total of s[x-1] units of time before beeing caught
    // its guarantee that we have A units (going left)
    // after this guard will close distance
    // if x=0 or m-x=0, then we will have left (b-a-x)/2*2
    // else we will have left b-a-x

    ll needed = s[x-1] + max((ll)0, (ll)(x-1-distance(s, lower_bound(s, s+m, s[x-1]))));
    ll delta = b-a-1-x;

    if (x == m || delta == 0) return (a-1)+delta/2*2+x >= needed;
    return (a-1)+delta+x >= needed;


    /*
    A B         -> 0
    A X B       -> 1
    A X X B     -> 2
    A X X X B   -> 3
    
    
    */
}

void solve() {
    cin >> n >> m >> a >> b;
    for (int i=0; i<m; i++) {
        cin >> s[i];
    }
    sort(s, s + m);

    ll l=0, r=m+1;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
