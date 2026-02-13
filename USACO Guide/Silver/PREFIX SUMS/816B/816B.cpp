#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> diff(200002, 0);
    int l, r;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }

    vector<int> prefix(200001);
    prefix[0] = 0;
    for (int i=1; i<=200000; i++) {
        diff[i] += diff[i-1];
        prefix[i] = ((diff[i] >= k) ? 1 : 0) + prefix[i-1];
    }

    for (int i=0; i<q; i++) {
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << '\n';
    }
}
