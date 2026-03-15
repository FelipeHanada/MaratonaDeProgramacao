#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;

int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}

int mult(int a, int b) {
    return ((ll)a * b) % md;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    array<int,3> rem;
    rem[0] = r/3 - (l-1)/3;
    rem[1] = (r+2)/3 - (l+1)/3;
    rem[2] = (r+1)/3 - (l)/3;
    
    int dp0 = 1, dp1 = 0, dp2 = 0;
    for (int i=0; i<n; i++) {
        tie(dp0, dp1, dp2) = make_tuple(
            add(mult(dp0, rem[0]), add(mult(dp1, rem[2]), mult(dp2, rem[1]))),
            add(mult(dp0, rem[1]), add(mult(dp1, rem[0]), mult(dp2, rem[2]))),
            add(mult(dp0, rem[2]), add(mult(dp1, rem[1]), mult(dp2, rem[0])))
        );
    }

    cout << dp0 << '\n';
}
