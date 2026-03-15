#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<float> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> b(n), c(n);
    for (int i=0; i<n; i++) {
        b[i] = int(floor(a[i]));
        c[i] = int(ceil(a[i]));
    }

    vector<int> ans(n);
    int curr = 0;
    for (int i=0; i<n; i++) curr += c[i];
    for (int i=0; i<n; i++) {
        if (curr > 0) {
            curr -= c[i];
            curr += b[i];
            ans[i] = b[i];
        } else {
            ans[i] = c[i];
        }
    }

    for (int x : ans) {
        cout << x << '\n';
    }
}