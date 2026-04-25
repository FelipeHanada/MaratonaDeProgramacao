#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
a
b
ba
bab
babba
*/

string x, y, yx;
vector<ll> sizes;
vector<vector<ll>> cnt;

ll get(ll i, char c) {
    if (i == 0) return 0;

    auto prefix_size_it = --upper_bound(sizes.begin(), sizes.end(), i);
    auto prefix_idx = distance(sizes.begin(), prefix_size_it);

    if (prefix_idx < 2) {
        return count(yx.begin(), yx.begin() + i, c);
    }

    return get(i - *prefix_size_it, c) + cnt[prefix_idx][c-'a'];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> y;
    yx = y + x;

    cnt.assign(2, vector<ll>(26, 0));
    for (char c : x) cnt[0][c - 'a']++;
    for (char c : y) cnt[1][c - 'a']++;

    sizes.resize(2);
    sizes[0] = x.size();
    sizes[1] = y.size();
    while (sizes[sizes.size()-1] + sizes[sizes.size()-2] <= 2e18) {
        sizes.push_back(sizes[sizes.size()-1] + sizes[sizes.size()-2]);

        cnt.push_back(vector<ll>(26));
        for (int i=0; i<26; i++)
            cnt.back()[i] = cnt[cnt.size()-2][i] + cnt[cnt.size()-3][i];
    }

    int q;
    cin >> q;
    while (q--) {
        ll l, r; char c;
        cin >> l >> r >> c;

        cout << get(r, c) - get(l - 1, c) << '\n';
    }
}
