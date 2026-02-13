#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define frac pair<ll, ll>

ll h, c, t;

double evl(frac a) {
    return a.first / (double)a.second;
}

frac simplify(frac a) {
    ll d = gcd(a.first, a.second);
    return {a.first / d, a.second / d};
}

frac temp(double k) {
    return simplify({h*(k+1) + c*k, 2*k+1});
}

void solve() {
    cin >> h >> c >> t;

    int lower = 0, upper = INT32_MAX - 1;
    while (lower < upper) {
        int mid = lower + (upper - lower + 1) / 2;

        frac tmp = temp(mid);
        if (evl(tmp) < t) {
            upper = mid - 1;
        } else {
            lower = mid;
        }
    }

    frac tmp1 = temp(lower);
    tmp1.first = abs(tmp1.first - t * tmp1.second);
    tmp1 = simplify(tmp1);
    
    frac tmp2 = temp(lower + 1);
    tmp2.first = abs(tmp2.first - t * tmp2.second);
    tmp2 = simplify(tmp2);
    
    pair<double, int> ans = {evl(tmp1), lower*2+1};
    if (tmp1.first * tmp2.second > tmp2.first * tmp1.second) {
        ans = {evl(tmp2), (lower + 1)*2+1};
    }
    ans = min(ans, {abs((h + c) / 2 - t), 2});

    cout << ans.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    for (int i=0; i<t; i++) {
        solve();
    }
}