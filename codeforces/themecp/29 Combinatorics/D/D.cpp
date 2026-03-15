#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

int mult(int a, int b) {
    return ((ll)a * b) % md;
}

int inv(int x) {
    return x <= 1 ? x : md - (ll)(md/x) * inv(md%x) % md;
}

int main() {
    int n;
    cin >> n;


    int facn = 1;
    for (int i=2; i<=n; i++) facn = mult(facn, i);
    int fac2n = facn;
    for (int i=n+1; i<=2*n; i++) fac2n = mult(fac2n, i);

    cout << mult(
        mult(fac2n, mult(2*n+1, 2*n+2)),
        mult(inv(mult(facn, n+1)), inv(mult(facn, n+1)))
    ) - 1 << '\n';
}
