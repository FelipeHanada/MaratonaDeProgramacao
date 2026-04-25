#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll x, y;
        cin >> x >> y;

        ll zz = y / x;
        if (x * (zz - 1) > x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

/*
y = p * x (para um inteiro p)
PROBLEMA: encontrar z tal que z = q * x e 1 < q < p (q é inteiro)

RESULTADO CONHECIDO: p e p-1 são coprimos

Podemos pegar o maior Z que satisfaz o problema.
    z = (p-1) * x


=> existe um z sse. z = (p-1) * x é solução
*/
