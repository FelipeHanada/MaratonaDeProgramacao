#include <bits/stdc++.h>
using namespace std;


/*
Bob nunca joga
    Se bob faz um movimento, Alice pode repeti-lo e aumentar o valor de f(n)
Se trata de encontrar a jogada ótima para Alice.


*/

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    ll cost = 0;
    for (int i=0; i<n; i++) cost += a[i] * (i % 2 ? -1 : 1);

    if (n == 1) {
        cout << cost << '\n';
        return;
    }

    /*
    1. trocar pos ímpar com pos ímpar = trocar 1 com o ceil(n/2)*2-1
    2. trocar pos par com pos par = trocar 2 com o floor(n/2)*2
    3. trocar pos ímpar com pos par
        delta = r - l + 2*impar - 2*par
    */
    ll ans = max((n-1)/2*2, (n-2)/2*2);

    ll best[2] = { INT32_MIN, INT32_MIN };
    for (int i=0; i<n; i++) {
        ans = max(ans, best[(i+1)%2] + (i%2?1:-1)*2*a[i] + i);
        best[i%2] = max(best[i%2], (ll)(i%2?1:-1)*2*a[i] - i);
    }

    cout << max(cost, cost + ans) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}