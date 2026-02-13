#include <bits/stdc++.h>
using namespace std;


int r, n, m;
void mult(vector<int> a, vector<int> b, vector<int>& out) {
    out[0] = ((a[0] * b[0]) % r + (a[1] * b[2]) % r) % r;
    out[1] = ((a[0] * b[1]) % r + (a[1] * b[3]) % r) % r;
    out[2] = ((a[2] * b[0]) % r + (a[3] * b[2]) % r) % r;
    out[3] = ((a[2] * b[1]) % r + (a[3] * b[3]) % r) % r;
}

int main() {
    cin >> r >> n >> m;

    vector<vector<int>> prefix(n+1, vector<int>(4));
    prefix[0][0] = 1;
    prefix[0][1] = 0;
    prefix[0][2] = 0;
    prefix[0][3] = 1;

    vector<int> v(4);
    for (int i=0; i<n; i++) {
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        mult(prefix[i], v, prefix[i+1]);
    }

    int left, right;
    while (m--) {
        cin >> left >> right;

        vector<int> inv(4);
        inv[0] = prefix[left-1][3];
        inv[1] = -prefix[left-1][1];
        inv[2] = -prefix[left-1][2];
        inv[3] = prefix[left-1][0];

        int det = prefix[left-1][0] * prefix[left-1][3] - prefix[left-1][1] * prefix[left-1][2];

        vector<int> ans(4);
        mult(inv, prefix[right], ans);
        cout << ans[0] / det << ' ' << ans[1] / det << '\n' << ans[2] / det << ' ' << ans[3] / det << '\n' << '\n';
    }
}
