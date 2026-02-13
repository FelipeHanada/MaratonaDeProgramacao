#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;

int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}

int prod(int a, int b) {
    return ((ll)a * b) % md;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int fac[1001];
    fac[0] = 1;
    for (int i=1; i<=1000; i++) fac[i] = prod(fac[i-1], i);

    int n, x, pos;
    cin >> n >> x >> pos;

    int l = 0, r = n;
    int big = 0, small = 0, any;
    while (l < r) {
        int mid = (l + r) / 2;
        if (mid == pos) {
            l = mid + 1;
        } else if (mid <= pos) {
            small++;
            l = mid + 1;
        } else {
            big++;
            r = mid;
        }
    }
    any = n - big - small - 1;

    // the answer is: comb(X, small)*small! * comb(Y, big)*big! * any!
    // X = x-1, Y = n-x
    int BIG = n-x, SMALL = x-1;

    if (big > BIG || small > SMALL || any < 0) {
        cout << "0\n";
        return 0;
    }

    int ans = fac[any];
    for (int i=BIG-big+1; i<=BIG; i++) ans = prod(ans, i);
    for (int i=SMALL-small+1; i<=SMALL; i++) ans = prod(ans, i);

    cout << ans << '\n';
}