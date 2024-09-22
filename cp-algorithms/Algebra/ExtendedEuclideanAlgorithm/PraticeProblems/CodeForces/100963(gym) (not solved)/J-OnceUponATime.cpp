#include <bits/stdc++.h>
using namespace std;


int ext_gcd(int a, int b, int &x, int &y) {
    x = 1; y = 0;
    int x1 = 0, y1 = 1;
    while (b != 0) {
        int q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}

int main() {
    freopen("once.in", "r", stdin);
    freopen("once.out", "w", stdout);

    int n, m, a, k, x, y;
    while (true) {
        cin >> n >> m >> a >> k;
        if (n == 0 && m == 0 && a == 0 && k == 0) break;

        int c = a + k - n;
        int g = ext_gcd(m, k, x, y);

        if (c % g) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        x *= g; y *= -g;

        

        int ans = n + m * x * g;
        cout << ans << endl;
    }
}
