#include <bits/stdc++.h>
using namespace std;


/*
Suponha sem perda de generalidade que é a vez de Alice.
    Queremos argumentar que Bob perde se escolher uma pilha de tamanho > 1.

Para isso, tome um tabuleiro T e a pilha escolhida por Bob p.

Vamos considerar dois casos:

I) O tabuleiro T sem a pilha p é uma posição vencedora para o segundo jogador
    (Alice vence, caso a posição seja atingida após sua jogada)
    Basta que Alice remova toda a pilha p.

II) O tabuleiro T sem a pilha p é uma posição vencedora para o segundo jogador
    (Quem fizer a jogada que mover para essa posição perde)
    Se p tem somente uma pedra, Bob ganha.
    Caso contrário, Alice remove toda pedra exceto uma de p
        e escolhe p na jogada de Bob.

Assim, é sempre ótimo escolher pilhas de tamanho 1, pois caso contrário
    você perde instantaneamente.
*/

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        int count1 = count(a.begin(), a.end(), 1);

        if (count1 == n) {
            cout << (count1 % 2 ? "Alice" : "Bob") << '\n';
        } else {
            cout << (count1 % 2 ? "Bob" : "Alice") << '\n';
        }
    }
}