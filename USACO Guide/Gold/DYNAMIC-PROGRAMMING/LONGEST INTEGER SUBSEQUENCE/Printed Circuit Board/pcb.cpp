#include <bits/stdc++.h>
using namespace std;


/*
let two connectors Xi1, Xi2 and Xj1, Xj2 (Xi1 < Xj1)
i and j cannot be on the same layer iff. Xi2 > Xj2
(eq. i and j can be on the same layer iff. Xi2 < Xj2 *the points are distinct)

then the task turns out to be to find the minimum number of LISes that cover all the points
this number is simply the size of the Largest non-Increasing Subsequence 
eq. we can find the Largest non-Decreasing Subsequence in the inverted vector
*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> conn(n);
    for (int i=0; i<n; i++) {
        cin >> conn[i].first >> conn[i].second;
    }
    sort(conn.begin(), conn.end(), greater<pair<int, int>>());

    vector<int> dp;
    dp.push_back(INT32_MIN);
    for (int i=0; i<n; i++) {
        auto ub = upper_bound(dp.begin(), dp.end(), conn[i].second);
        if (ub == dp.end()) dp.push_back(conn[i].second);
        else *ub = conn[i].second;
    }
    cout << dp.size() - 1 << '\n';
}
