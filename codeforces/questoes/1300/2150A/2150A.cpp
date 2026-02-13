#include <bits/stdc++.h>
using namespace std;


/*
3 4
ABA
1 4 9 10

B W W B W W W W B B W W W W W W W ...
1 1
2 2 2

se a última instrução do anterior foi A,
    então ele para no mesmo indice que o anterior
        antes de executar a próxima inst.

se a última instrução do anterior foi B,
    então ele para no próximo indice W depois da posição do anterior
        antes de executar a próxima inst.
*/

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> B;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        B.insert(x-1);
    }

    int last = 1;
    if (s[0] == 'A') B.insert(1);
    else {
        int i=1;
        while (B.count(i)) i++;
        last = i;
        B.insert(i);
    }

    for (int i=1; i<n; i++) {
        if (s[i-1] == 'B') {
            last++;
            while (B.count(last)) last++;
        }

        if (s[i] == 'A') {
            last++;
        } else {
            last++;
            while (B.count(last)) last++;
        }
        B.insert(last);
    }

    cout << B.size() << '\n';
    for (int i : B) {
        cout << i + 1 << ' ';
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