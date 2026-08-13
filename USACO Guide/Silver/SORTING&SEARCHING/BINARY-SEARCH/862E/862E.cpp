#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];

    ll sA = 0;
    for (int i=0; i<n; i++) {
        sA += (a[i] * (i % 2 ? -1 : 1));
    }

    vector<ll> sB;
    int i=0, j = 0;
    ll curr = 0;
    while (j < n) {
        curr += b[j] * (j % 2 ? -1 : 1);
        j++;
    }
    sB.push_back(curr);
    while (j < m) {
        curr -= b[i];
        curr += b[j] * (n % 2 ? -1 : 1);
        curr *= -1;
        i++; j++;
        sB.push_back(curr);
    }
    sort(sB.begin(), sB.end());

    auto solve = [&]() -> ll {
        ll ans = INT64_MAX;
        auto lb = lower_bound(sB.begin(), sB.end(), sA);
        if (lb != sB.end()) ans = min(ans, *lb - sA);
        if (lb != sB.begin()) ans = min(ans, sA - *(lb-1));
        return ans;
    };

    cout << solve() << '\n';
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;

        if ((l - r) % 2) {
            sA += (l % 2 ? -x : x);
        }

        cout << solve() << '\n';
    }
}

/*
f(j) = abs(c_1 - c_2 + c_3 ... c_n)
ci = a_i - b_{i+j}

f(j) = abs(
    a_1 - a_2 + a_3 ... a_n
    - b_{j+1} + b_{j+2} - b_{j+3} ... b_m
)
let sA and sB be the summations (of a's and b's) of the formula

the objective is to find minimum abs(sA - sB)
that is, when sA and sB are nearest.

sB is the alternating sum of every window of size n

1 2 3 4 5
11 2 3 4 5 => 11 - 2 + 3 - 4 + 5 = 13
*/