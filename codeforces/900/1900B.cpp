#include <bits/stdc++.h>
using namespace std;


/*
quero fazer sobrar somente A
se B e C forem iguais, posso matar ambos
posso fazer a diferença de B e C diminuirem em 2 ao custo de 1 A
se min(B, C) > 0, posso aumentar 1 A sem aumentar a diferença

[algoritmo para fazer apenas A sobrar]
suponha B > C
passo 1: maximizando A
após C operações [A+ B- C-]:
    A' = A + C
    B' = B - C
    C' = C - C = 0

passo 2: reduzindo a diferença de B e C
após (B' - C') / 2 operações [A- B- C+]:
    para isso eu preciso de A' >= (B' - C') / 2 e B' >= (B' - C') / 2
        dessa forma, A + C >= (B - C) / 2  (observe que B' - C' = B - C)
        2*A + 2*C >= B - C
        2*A + 3*C >= B

	A'' = A' - (B - C) / 2 = A + C - (B - C) / 2 = A + 3/2 C - B/2
	B'' = B' - (B - C) / 2 = (B - C) - (B - C) / 2 = (B - C) / 2
	C'' = C' + (B - C) / 2 = (B - C) / 2

(você pode repetir os passos 1 e 2 até que B e C se eliminem)

passo 3: eliminando B e C
após (B - C) / 2 operações [A+ B- C-]:
	A''' = A'' + (B - C) / 2 = A + 2C - B
	B''' = C''' = 0


seja f([a, b, c]) = [a', b', c'] uma função definida pela execução dos seguintes passos:
    seja k' = max(b, c) e k'' = min(b, c)

    temos:
        a números A's
        k' números B's
        k'' números C's

    passo 1: executa-se a operação {A+, B-, C-} k'' vezes
        após isso teremos:
            a + k'' números A's
            k' - k'' números B's
            0 números C's
    
    passo 2: executa-se a operações
        
*/

int solve(int a, int b, int c) {
    int big = max(b, c);
    int small = b + c - big;
    int dif = big - small;

    return (dif % 2 == 0 && a >= 0.5 * big - 1.5 * small) ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, c;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> a >> b >> c;

        cout << solve(a, b, c) << " "
             << solve(b, a, c) << " "
             << solve(c, a, b) << endl;
    }
}
