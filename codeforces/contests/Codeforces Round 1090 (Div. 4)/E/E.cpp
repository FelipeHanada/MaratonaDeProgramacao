#include <bits/stdc++.h>
using namespace std;

#define _f first
#define _s second
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


// é o xor de (n+1)/2 elementos

/*
a1 a2 a3 ... an

WLOG a1 is the finalist

*/

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        int ans = INT32_MIN;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ans = max(ans, a[i] ^ a[j]);
            }
        }
        cout << ans << '\n';
    }
}
