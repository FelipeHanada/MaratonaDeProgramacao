#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    // grafos, dp, geo

    // 3graf = 2dp
    // 2geo = 5graf

    char k;
    cin >> k;

    switch (k) {
        case 'A':
            cout << (ll) (a + 3/(double)2 * b + 5/(double)2 *c) << '\n';
            break;
        case 'B':
            // geo = 5/2 graf = 5/2 * 2/3 dp
            cout << (ll) (2/(double)3 * a + b + 5/(double)3 * c) << '\n';
            break;
        default:
            // dp = 3/2 graf = 3/2 * 2/5 geo
            cout << (ll) (2/(double)5 * a + 3/(double)5 * b + c) << '\n';
    }
}