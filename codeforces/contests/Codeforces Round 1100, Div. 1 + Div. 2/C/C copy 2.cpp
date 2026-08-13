#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        vector<int> small(n), big(n);
        small[0] = -abs(a[0]);
        big[0] = a[0];

        vector<int> bsmall(n), bbig;

        for (int i=1; i<n; i++) {
            small[i] = small[i-1] - abs(a[i]);
            if (a[i] < 0) big[i] = big[i-1] + a[i];
            else big[i] = max(big[i] + a[i], -small[i-1] -a[i]);
        }

        cout << big[n-1] << '\n';
    }
}
