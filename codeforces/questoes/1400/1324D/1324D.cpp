#include <bits/stdc++.h>
using namespace std;


// two pairs (ai,bi), (aj,bj) is good
// iff. ai+aj > bi+bj
// equivalently (ai-bi) + (aj-bj) > 0

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (int i=0; i<n; i++) cin >> pairs[i].first;
    for (int i=0; i<n; i++) cin >> pairs[i].second;
    vector<int> diff(n);
    for (int i=0; i<n; i++) diff[i] = -(pairs[i].first - pairs[i].second);
    sort(diff.begin(), diff.end());

    ll ans = 0;
    for (auto it = diff.begin(); it != diff.end(); it++) {
        // then for each topic we need to find the number of topic
        // that makes diff[i] + diff[j] > 0 OR -(-diff[i]) > -diff[j]
        ans += distance(diff.begin(), lower_bound(diff.begin(), it, -*it));
    }

    cout << ans << '\n';
}
