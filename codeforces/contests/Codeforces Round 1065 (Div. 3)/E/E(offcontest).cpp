#include <bits/stdc++.h>
using namespace std;


/*
1 2 3 4 9 6 7 8 9 10 ... n

_ 2 4 _ 6 8 _ 10 12 _ 16 18 _ 20 _ 3 9 _ 15 21


ceil(n/4) triplas de 2
ceil(n/12) triplas de 3

ceil(n/4) + n/2 números gastos
ceil(n/12) + n/6 números gastos

restam
n - ceil(n/4) - ceil(n/12) - n/2 - n/6
<= n - n/4 - n/12 - n/2 - n/6
= n - (3 + 1 + 6 + 2)n/12
= n - (12)n/12
= 0
essa construção usa todos os números

e gera no máximo 3 índices ruins (transição das triplas de 2 para as triplas de 3)
_ 2 2 _ 2 2 _ 3 3
          ^ indice potencialmente ruim
_ 2 2 _ 2 _ 3 (pior caso)
      ^ ^ ^ indices potenalmente ruins
*/

void solve() {
    int n;
    cin >> n;

    int last = 1;
    for (int i=2; i<=n; i+=4) {
        cout << last << ' ' << i << ' ';
        if (i + 2 <= n) cout << i + 2 << ' ';
        if (last % 6 == 1) last += 4;
        else last += 2;
    }

    for (int i=3; i<=n; i+=12) {
        if (last <= n) {
            cout << last << ' ';
            if (last % 6 == 1) last += 4;
            else last += 2;
        }
        cout << i << ' ';
        if (i + 6 <= n) cout << i + 6 << ' ';
    }

    while (last <= n) {
        cout << last << ' ';
        if (last % 6 == 1) last += 4;
        else last += 2;
    }

    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}