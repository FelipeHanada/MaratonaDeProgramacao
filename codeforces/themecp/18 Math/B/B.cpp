#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    ll n, m, k;
    cin >> n >> m >> k;


    if (k < n) {
        cout << 1 + k << " 1\n";
        return 0;
    }
    k -= n - 1;

    ll row = (k-1) / (m-1);

    if (row % 2) {
        cout << n - row << ' ' << m - (k-1)%(m-1) << '\n';
    } else {
        cout << n - row << ' ' << 2 + (k-1)%(m-1) << '\n';
    }
}