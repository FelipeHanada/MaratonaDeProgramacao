#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);
#define _f first
#define _s second
using ll = long long;
constexpr int md = 0;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}


int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n-1);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) cin >> b[i];

    vector<int> dp0(n), dp1(n);
    dp0[0] = (a[0]%2 == 1);
    dp1[0] = (a[0]%2 == 0);

    for (int i=1; i<n; i++) {
        if (b[i-1] == 0) {
            dp0[i] = dp0[i-1] + (a[i]%2 == 1);
            dp1[i] = dp1[i-1] + (a[i]%2 == 0);
        } else { // precisa ser 1
            dp0[i] = dp1[i-1] + (a[i]%2 == 1);
            dp1[i] = dp0[i-1] + (a[i]%2 == 0);
        }
    }

    cout << min(dp0[n-1], dp1[n-1]) << '\n';
}
