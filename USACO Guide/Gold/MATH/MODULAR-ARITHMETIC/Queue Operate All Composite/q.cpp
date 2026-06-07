#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int md = 998244353;
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
int inv(int a) { return binpow(a, md - 2); }

int main() {
    int q; cin >> q;
    int a = 1, b = 0;
    queue<pair<int, int>> f;
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int aa, bb; cin >> aa >> bb;
            a = mult(a, aa);
            b = add(bb, mult(aa, b));
            f.push({ aa, bb });
        } else if (t == 1) {
            auto [aa, bb] = f.front(); f.pop();
            a = mult(a, inv(aa));
            b = sub(b, mult(a, bb));
        } else {
            int x; cin >> x;
            cout << add(mult(a, x), b) << '\n';
        }
    }
}