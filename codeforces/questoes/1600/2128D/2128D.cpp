#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
considerando um intervalo [l, r],

um corolário comum do teorema de Dilworth é que
o tamanho da maior subsequencia decrescente de B
é a menor quantidade de subsequencias crescentes que cobrem B


tome um indice i tal que a[i] < a[i+1], é fácil mostrar que:
    => a[i+1] > [i+2], ..., a[n]
prova:
    sabemos que max{a[i], a[i+1]} > a[i+2]
    como a[i] < a[i+1], temos max{a[i], a[i+1]} = a[i+1]
    logo a[i+1] > a[i+2]

    a partir daí temos
    max{a[i+1], a[i+2]} = a[i+1] > a[i+3]
    a[i+1] > max{a[i+2], a[i+3]} > a[i+4]
    a[i+1] > max{a[i+3], a[i+4]} > a[i+5]
    ...
    a[i+1] > max{a[n-2], a[n-1]} > a[n]

um resultado direto desta afirmação, é que não existe tripla
    i < j < k tal que a[i] < a[j] < a[k]
        (pois a[j] seria maior do que os seguintes)


assim, a toda IS dentro dos subarrays de A é de tamanho 1 ou 2

agora resta provar que toda IS de tamanho 2 a[i], a[j]
    pode ser "melhorada" tomando uma nova IS a[k], a[k+1]
    com k>=i e k+1<=j

tome a[i] < a[j] para j > i + 1
    como não existem triplas a[i] < a[k] < a[j]
    existe um elemento k > i e k < j tal que
    I) a[i] > a[k] < a[j]
    II) ou a[i] < a[k] > a[j]
    assim, podemos tomar o par a[k], a[j]
        ou a[i], a[k]

    esse processo pode ser repetido iterativamente
        para se obter um par a[k], a[k+1] dentro do intervalo [i, j]


logo, como os "melhores" IS's para cobrir A são elementos adjacentes
    basta contar a maior quantidade de IS's disjuntos de tamanho 2
    que podemos obter é simplesmente a quantidade de pares a[i] < a[i+1]
    dentro de A.

pelo teorema de Mirsky, a LDS de A será
    quantidade mínima de IS's para cobrir A
    = o tamanho de A - quantidade máxima de IS's disjuntas de tamanho 2
    = o tamanho de A - quantidade de pares a[i] < a[i+1] dentro de A


isso pode ser calculado para todo intervalo [l, r] de A da seguinte forma
res := soma do tamanho de todos os intervalos
        - para todo i tal que a[i] < a[i+1], quantidade de intervalos [l, r]
            tal que l <= i e i + 1 <= r
*/

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        ll ans = 0;
        for (int i=1; i<=n; i++) {
            ans += i * ll(n - i + 1);
        }

        for (int i=0; i<n-1; i++) {
            if (a[i] < a[i+1]) {
                // subtracts the number of subarrays [l, r]
                // that contains i and i+1
                // there is (i+1) possible l's
                // and n-(i+1) possible r's
                ans -= ll(i+1) * (n-i-1);
            }
        }

        cout << ans << '\n';
    }
}
