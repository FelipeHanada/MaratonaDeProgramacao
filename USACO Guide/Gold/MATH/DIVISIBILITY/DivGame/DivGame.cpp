#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

int main() {
    ll n; cin >> n;

    map<int, int> factors;
    for (int i=2; i*i<=n; i++) {
        if (n % i == 0) {
            factors.emplace(make_pair(i, 0));
        }
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors.emplace(make_pair(n, 1));
    }

    int ans = 0;
    for (auto f : factors) {
        ans += floor(-1 + sqrt(1 + 8 * f.second)) / 2;
    }

    cout << ans << endl;
}