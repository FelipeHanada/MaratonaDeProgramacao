#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 61;
int n;
char a[MAX_N], b[MAX_N];
int solve(int i, char destino) {
    // move o disco i-ésimo disco para a posição desejada

    if (a[i] == destino) {
        return 0;
    }

    int ans = 0;
    // mover todos os discos para a pilha que não é a destino
    char aux = 'A' + 'B' + 'C' - a[i] - destino;
    for (int j=i-1; j>=0; j--) {
        ans += solve(j, aux);
    }

    cout << "MOVA O DISCO DA PILHA " << a[i] << " PARA A PILHA " << destino << "\n";
    a[i] = destino;
    return ans + 1;
}


int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    int ans = 0;

    // for (int i=n-1; i>=0; i--) {
    //     ans += solve(i, b[i]);
    //     cout << "-------------------\n";
    // }

    cout << ans << "\n";
}