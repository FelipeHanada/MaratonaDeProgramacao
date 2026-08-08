#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;

    }
}

/*
existem 6 operações possíveis

não faz sentido usar mais de 2 operações em uma letra

a) não deve ser operado
b) deve ser transformado em um a:
    b -> a
    b -> c -> a
c) deve ser transformado em um a, se não der em um b:
    c -> a
    c -> b -> a
    c -> b


*/
