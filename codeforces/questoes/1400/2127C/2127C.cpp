#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

/*
sem perda de generalidade, podemos assumir que a[i] >= b[i]

o melhor que B consegue fazer se A escolhe i, j:
    melhor pontuacao possivel: a[i+1] + max(a[i], b[i+1]) - min(a[i], b[i+1]) - b[i]

    se ele não precisa mudar:
        a[i+1] + a[i] - b[i] - b[i+1]
    se ele troca:
        a[i+1] + b[i+1] - b[i] - a[i]

A deseja minimizar a melhor troca, então precisamos escolher i e j tal que
    a[i+1] + b[i+1] - b[i] - a[i] é mínimo

a[i+1] + b[i+1] - b[i] - a[i] é a distância de Manhattan entre dois pontos:
    a menor distância entre qualquer par de pontos pode ser calculada da seguinte forma:
    1) ordena a partir de a.
    2) res. = min { distância entre dois adjacentes }

logo a melhor jogada de A é algum i, j tal que j = i + 1 (depois que a é ordenado)
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) cin >> a[i]._1;
    for (int i=0; i<n; i++) cin >> a[i]._2;
    for (int i=0; i<n; i++) if (a[i]._1 < a[i]._2) swap(a[i]._1, a[i]._2);
    sort(a.begin(), a.end());

    ll ans = INT32_MAX;
    for (int i=0; i<n-1; i++) {
        ll change = a[i+1]._1 + max(a[i+1]._2, a[i]._1) - min(a[i+1]._2, a[i]._1) - a[i]._2;
        ll dchange = abs(a[i]._1 - a[i]._2) + abs(a[i+1]._1 - a[i+1]._2);
        ans = min(ans, change - dchange);
    }
    for (int i=0; i<n; i++) {
        ans += abs(a[i]._1 - a[i]._2);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}