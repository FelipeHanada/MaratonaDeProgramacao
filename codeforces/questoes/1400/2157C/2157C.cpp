#include <bits/stdc++.h>
using namespace std;


/*
6 2 2
1 1 3 -> 
2 2 6 => não tem 2

min é associativo, podemos tomar a união de todos os intervalos de min


3 3 3 3 3 3
^ ^ ^ S
  ^ ^ ^ ^ ^ [2, 6]
  3 3 -> intersecção
2 3 3 


Seja [a1, b1], [a2, b2], ..., [ap, bp] a família de intervalos com c = 1
    e [c1, d1], ..., [cq, dq] a família dos intervalos com c = 2

Seja A = [a1, b1] U ... U [ap, bp] e C = [c1, d1] U ... U [cq, dq]
    a intersecção de [ci, di] com A não pode conter 2's, logo deve conter valores maiores do que k
        WLOG podemos assumir que todo valor na intersecção é k+1

Todo elemento de A\B pode ser 2 

o desafio é preencher B\A, isso pode ser feito usando um algoritmo greedy
*/

#define _1 first
#define _2 second

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<pair<int, int>> a, b;
    for (int i=0; i<q; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            a.push_back({l, r});
        } else {
            b.push_back({l, r});
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (!a.empty()) {
        vector<pair<int, int>> new_a;
        new_a.push_back(a.front());
        for (int i=1; i<a.size(); i++) {
            if (new_a.back()._2 + 1 >= a[i]._1) {
                new_a.back()._2 = max(new_a.back()._2, a[i]._2);
            } else {
                new_a.push_back(a[i]);
            }
        }
        swap(a, new_a);
    }

    if (!b.empty()) {
        vector<pair<int, int>> new_b;
        new_b.push_back(b.front());
        for (int i=1; i<b.size(); i++) {
            if (new_b.back()._2 + 1 >= b[i]._1) {
                new_b.back()._2 = max(new_b.back()._2, b[i]._2);
            } else {
                new_b.push_back(b[i]);
            }
        }
        swap(b, new_b);
    }

    vector<int> ans(n+1, k);
    int last = 0;
    for (auto [c, d] : b) {
        for (int i=c; i<=d; i++) {
            auto ub = upper_bound(a.begin(), a.end(), make_pair(i, INT32_MAX));
            if (ub != a.begin() && (--ub)->_2 >= i) {
                // ta na interseccao
                ans[i] = k + 1;
            } else {
                ans[i] = last++;
                last %= k;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}