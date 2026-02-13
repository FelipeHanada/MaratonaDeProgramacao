#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b;
    bool c;

    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        scanf("%d:%d", &a, &b);

        c = true;  // AM

        if (a >= 12) c = false;  // todos os horários depois (incluindo) 12:00 são PM

        //  converte o formato de a para 12h       
        if (a > 12) a -= 12;     // se o horário tiver H > 12, ele deve ser reduzido em 12
        if (a == 0) a = 12;      // meia noite é representado como 12 AM

        printf(a < 10 ? "0" : "");  // verifica se é um número de 1 digito (para adicionar 0 na frente)
        printf("%d:", a);

        printf(b < 10 ? "0" : "");
        printf("%d ", b);
        
        printf(c ? "AM" : "PM");
        printf("\n");
    }
}