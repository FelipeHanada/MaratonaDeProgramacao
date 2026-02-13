#include <bits/stdc++.h>
using namespace std;

/*
let each cow be described by its start and its velocity (si,vi)
	two cows (si,vi) and (sj,vj) with si < sj can't occupy the same lane
    iff. cow i surpasses cow j
    eq. si + vi * t >= sj + vj * t for some 0 < t <= T
    if vi <= vj, it is obvious that cow i cant surpass cow j
    else vi > vj, we can check for t=T
        si + vi * T >= sj + vj * T   ===  ei >= ej
        where ei and ej are the ending positions of cow i and j respectively
    therefore, cow i and j can be on the same lane iff. ei < ej

since all lines are increasing subsequences,
    the minimum number of subsequences to cover all the cows
    is the size of the longest non-increasing subsequence
    eq. size of the longest non-decreasing subsequence (if we take the negatives)
*/

#define ll long long

int main() {
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);

    int n, t;
    cin >> n >> t;
    vector<ll> dp;
    dp.push_back(INT64_MIN);
    ll x, v;
    for (int i=0; i<n; i++) {
        cin >> x >> v;
        ll ei = x + v * t;

        auto it = upper_bound(dp.begin(), dp.end(), -ei);
        if (it == dp.end()) {
            dp.push_back(-ei);
        } else {
            *it = -ei;
        }
    }

    cout << dp.size() - 1 << '\n';
}
