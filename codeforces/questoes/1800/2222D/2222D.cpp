#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<pair<ll, int>> b(n);
        b[0] = { 0, 0 };
        for (int i=1; i<n; i++) b[i] = { b[i-1].first + a[i-1], i };
        sort(b.rbegin(), b.rend());

        vector<int> p(n);
        for (int i=0; i<n; i++) p[b[i].second] = i;

        for (int x : p) cout << x + 1 << ' ';
        cout << '\n';
    }
}


/*
let b[i] = a[1] + ... + a[i-1]

the value of an inversion (i, j)
    is b[j] - b[i]

th best case scenario occurs when, for every pair (i, j)
    if b[i] < b[j], then p[i] > p[j]        (this inversion increase beauty)
    if b[j] > b[i], then p[i] < p[j]        (this inversion would decrease beauty)

then, its always optimal to choose the smaller p[i] for the bigger b[i]
    we can sort i by b[i] and assign p[i] in order.
*/