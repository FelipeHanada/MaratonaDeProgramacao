#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

/*
[a, b], [c, d], [e, f] formam um ciclo de tamanho 3
iff. WLOG [a, b] U [c, d] = [e, f]
    e [a, b] intersec. [c, d] = [e, f]

neste caso, basta escolher o maior
portanto a resp. é o tamanho a união de todos os intervalos
*/

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    map<int, pair<int, int>> m;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        m[a] = max(m[a], {b, i});
    }

    cout << m.size() << '\n';
    for (auto [a, p] : m) {
        cout << p.second + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}