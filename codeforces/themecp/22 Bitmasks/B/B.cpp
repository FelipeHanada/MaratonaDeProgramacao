#include <bits/stdc++.h>
using namespace std;


using ll = long long;


constexpr int md = int(1e9)+7;
int mult(int a, int b) {
    return ((ll)a * b) % md;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        int x = a[0];
        for (int i=1; i<n; i++) x &= a[i];
        int y = count(a.begin(), a.end(), x);

        if (y < 2) {
            cout << "0\n";
        } else {
            int fac = 1;
            for (int i=2; i<=n-2; i++) {
                fac = mult(fac, i);
            }
            cout << mult(mult(y, y-1), fac) << '\n';
        }
    }
}
