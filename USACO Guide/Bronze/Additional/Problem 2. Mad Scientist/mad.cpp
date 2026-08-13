#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n; cin >> n;
    string a, b; cin >> a >> b;

    int i = 0;
    int ans = 0;
    for (; i < n; i++) {
        while (i < n && a[i] == b[i]) i++;
        if (i < n) {
            ans++;
            while (i < n && a[i] != b[i]) i++;
        }
    }

    cout << ans << '\n';
}

/*
7
GHHHGHH

HHGGGHH

GHGGGHH
^

GHHHGHH
  ^^

seja i o primeiro indice tal que A[i] != B[i]
    a gente precisa que um numero ímpar de intervalos contenha i


1) ignora o prefixo correto
2) se a string for vazia, termina
3) cc. vai até o próximo indice onde ela é correta e soma a resp. em 1

*/
