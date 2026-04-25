#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;


/*

1 digitos: 4 numeros

2 digitos: 3 + (4*4) numeros

3 digitos: 3 + (4^3 + 8*4) numeros


d digitos: quantidade de potencias de 2 com d digitos (pode ser computado facilmente)
            + quantidade de concatenações de potencias de 2 que tem d digitos (computado em tempo linear: O(d) ou O(logn))


d[i] = quantidade de números da seq com i digitos

d[1] = 4
d[2] = 3 + d[1]*d[1] = 19
d[3] = 3 + d[1]*d[2] + d[2]*d[1] = 
d[4] = 4 + d[1]*d[3] + d[3]*d[1] + d[2]*d[2]
        (acontece overcounting)

suponha que sabemos a quantidade de digitos do N-ésimo número da seq. como podemos reconstruir?

iterar da direita para a esquerda?

*/

int main() {

}