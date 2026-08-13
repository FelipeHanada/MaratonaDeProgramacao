#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);
constexpr int md = int(1e9)+7;
inline int add(int a, int b) { return ((a%md) + (b%md)) % md;}
inline int sub(int a, int b) { return ((a%md) - (b%md) + md) % md;}
inline int mult(int a, int b) { return ((ll)(a%md) * (b%md)) % md;}
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
inline int inv(int a) { return binpow(a, md-2); }


int main() {

}

/*
I) alguém com < max(A)-1 nunca ganha
II) alguém com max(A)-1 pontos só ganha se vencer, e todos com max(A) pontos perderem
III) alguém com max(A) pontos, vence se:
    III.a) ganha
    III.b) perde, mas todos com max(A) pontos também perderem

I) é fácil => P[vencer] = 0

II) não pode haver alguém com max(A) pontos jogando contra alguém com max(A) pontos

    temos que considerar as outras pessoas com max(A)-1 pontos
        (exceto o jogador corrente)

    interessa:
    a) quantos com max(A)-1 pontos estão contra alguém com max(A) pontos
    b) quantos com max(A)-1 pontos estão contra alguém com max(A)-1 pontos
    c) quantos com max(A)-1 pontos estão contra alguém com < max(A)-1 pontos

    a) todos eles precisam ganhar
        probabilidade: 0.5^|a|
        o coin flip precisará ser tirado com esses jogadores

    b) o jogador corrente precisa ganhar
        o coin flip precisará ser tirado com metade desses jogadores

    c) tanto faz quem ganha
        o coin flip precisará ser tirado com os jogadores com max(A)-1
            pontos que vencerem

        a quantidade de jogadores que vencem é uma dist. Binomial

III)
*/
