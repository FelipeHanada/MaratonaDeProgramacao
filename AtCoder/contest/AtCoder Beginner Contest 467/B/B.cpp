#include <bits/stdc++.h>
using namespace std;
#define ios::sync_with_stdio(0); cin.tie(nullptr);
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
    int n; cin >> n;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int a, b; string c;
        cin >> a >> b >> c;

        if (c == "keep") {
            ans += b - a;
        }
    }

    cout << ans << '\n';
}
