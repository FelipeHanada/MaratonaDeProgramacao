#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }
    map<int, int> pos;
    for (int i=0; i<n; i++) pos[p[i]] = i;

    bool inv = 0;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y; x--; y--;
            if (inv) {
                // queremos swappar pos[x] pos[y]
                x = pos[x];
                y = pos[y];
            }
            
            swap(pos[p[x]], pos[p[y]]);
            swap(p[x], p[y]);
        } else {
            inv = !inv;
        }
    }

    if (inv) {
        for (int i=0; i<n; i++) p[i] = pos[i];
    }

    for (int x : p) cout << x + 1 << ' ';
    cout << '\n';
}

/*
5 1 2 3 4
-> query 2
2 3 4 5 1
-> query 1 (4, 5)
2 3 4 1 5
-> query 2
4 1 2 3 5           => (5 e 4 trocaram de lugar)
-> query 1 (4, 5)
4 1 2 5 3
-> query 2
2 3 5 1 4



P -> swap -> inv -> swap -> inv -> swap -> inv
    (           )

P -> inv -> swap(x,y) -> P*

P -> query2 -> query1 -> query1 -> P* -> query2 -> query -> P**
                                   inv(P*)                   inv(inv(P**)) = P**

podemos obter o inverso de P*?

vejamos:
1. swap em P => trivial
2. swap no inverso de P
    P = inv(swap(inv(P), x, y)), como isso afeta P?
    P[P'[x]] = y
    P[P'[y]] = x => troca os valores de posição

    conheço P, mas fizeram um swap em inv(P)
    depois do swap, eu quero saber quem é P


P                   = 4 5 1 2 3
inv(P)              = 3 4 5 1 2
swap(inv(P))        = 3 4 1 5 2  => swap(3, 4) => trocou valores 1 e 5 de lugar
inv(swap(inv(P)))   = 3 5 1 2 4  => indices 1 e 5 de lugar

P^-1[3] = pos[3] = 5
P^-1[4] = pos[4] = 1



10 8
7 3 2 4 8 5 10 9 1 6
2
1 4 10
1 6 9
2
1 9 10
1 3 10
2
1 4 6

7 3 2 4 8 5 10 9 1 6
-> inv
9 3 2 4 6 10 1 5 8 7
-> swap(4, 10)
9 3 2 7 6 10 1 5 8 4

*/
