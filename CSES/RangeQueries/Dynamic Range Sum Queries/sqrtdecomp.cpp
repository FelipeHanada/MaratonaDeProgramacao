#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int N = int(2e5) + 5;
int B;
int a[N];
ll b[N];
void sq_set(int i, int v) {
    b[i/B] += v - a[i];
    a[i] = v;
}
ll sq_get(int l, int r) {
    ll ans = 0;
    while (l % B && l < r) ans += a[l++];
    while (r % B && l < r) ans += a[--r];
    if (l == r) return ans;
    while (l != r) {
        ans += b[l/B];
        l += B;
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;

    B = sqrt(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) b[i/B] += a[i];

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        x--;

        if (op == 1) {
            sq_set(x, y);
        } else {
            cout << sq_get(x, y) << '\n';
        }
    }
}