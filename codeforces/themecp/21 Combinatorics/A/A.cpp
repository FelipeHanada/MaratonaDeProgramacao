#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int md = int(1e9)+7;

int mult(int a, int b) {
    return ((ll)a * b) % md;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        int ans = 1;
        for (int i=0; i<k; i++) {
            ans = mult(ans, n);
        }

        cout << ans << '\n';
    }
}
