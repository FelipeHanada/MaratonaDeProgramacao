#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9) + 7;
inline int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
inline int mult(int a, int b) { return ((ll)a * b) % md; }
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

int fat[int(1e6)+1];

int main() {
    fat[0] = 1;
    for (int i=1; i<=int(1e6); i++) fat[i] = mult(fat[i-1], i);

    int n; cin >> n;
    // ans = number of chaotic permutations of size n
    int ans = fat[n];
    for (int i=1; i<=n; i++) {
        if (i & 1) ans = sub(ans, mult(fat[n], inv(fat[i])));
        else ans = add(ans, mult(fat[n], inv(fat[i])));
    }

    cout << ans << '\n';
}

/*
Seja P uma permutação
    P é caótica se P[i] != i para todo i

Seja Ai = permutações p t.q. p[i] = i

#P caóticas = #P - #P não caóticas
            = n! - #(A1 U A2 U ... U An)

pelo principio da Inclusão-Exclusão
#(A1 U A2 U ... U An)
    = #A1 + #A2 + ... + #An
      - intersecções 2 a 2
      + intersecções 3 a 3
      ...
      +- intersecção n a n

como a intersecção de k conjuntos Ai distintos tem card. (n-k)!

#(A1 U A2 U ... U An)
    = n * (n-1)!
      - comb(n, 2) * (n-2)!
      + comb(n, 3) * (n-3)!
      ...
      +- comb(n, n) * (n-n)!

cada passo é
    comb(n, i) * (n-i)! = n!/(n-i)!/i! * (n-i)! = n!/i!
*/
