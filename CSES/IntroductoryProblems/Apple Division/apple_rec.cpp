#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int n;
vector<int> a;
ll ans;
ll sum, curr;
void solve(int i) {
    if (i == n) {
        ans = min(ans, abs(sum - 2 * curr));
        return;
    }

    curr += a[i];
    solve(i+1);
    curr -= a[i];
    solve(i+1);
}

ll solve2(int idx, vector<int> v, ll s1, ll s2, int n){
    if(idx==n) return abs(s1-s2);
    ll c = solve2(idx+1, v, s1+v[idx], s2, n);
    ll nc = solve2(idx+1, v, s1, s2+v[idx], n);
    return min(c, nc);
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sum = 0, curr = 0;
    for (int i=0; i<n; i++) sum += a[i];

    ans = INT64_MAX;
    solve(0);

    cout << ans << '\n';
}