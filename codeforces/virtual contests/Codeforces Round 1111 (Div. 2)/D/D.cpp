#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int n, q;
vector<int> a;
int flog2(int x) { return __builtin_clz(1) - __builtin_clz(x); }

int main() { _
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> q;
        a.resize(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<int> b = a;
        sort(b.begin(), b.end());

        bool good = 1;
        for (int i=0; good && i<n; i++) {
            good = a[i] == b[i];
        }
        if (good) {
            cout << "0\n";
            continue;
        }

        int l = -1, r = flog2(n) + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            ll block = (1LL << (mid + 1));

            good = 1;
            for (int i=0; good && i<n; i+=block) {
                map<int, int> cnt;
                for (int j=0; j<block && i+j<n; j++) cnt[a[i+j]]++;

                for (int j=0; j<block && i+j<n; j++) {
                    if ((--cnt[b[i+j]]) < 0) good = 0;
                }
            }

            if (good) r = mid;
            else l = mid;
        }

        cout << (1 << r) << '\n';
    }
}

/*
binsearch <---- se pode ser k-sorted, então pode ser k+1-sorted

como verificar k-sortabilidade?

0 -> pode trocar com os k+1 primeiros indices



6 0
2 5 3 4 1 6

1 2 3 4 5 6

o v(1), v(2) precisam estar na mesma CC
o v(1), v(5) precisam estar na mesma CC
  v(2), v(5)


  da pra iterar k=1..inf? até que as componentes conexas se formem?

no pior caso, o maior k necessário pra ordenar é k = n - 1


k = 1 -> conecta 2x com 2x+1
k = 2 -> divide em grupos de 4
k = 4 -> divide em grupos de 8
k = 8 -> divide em grupos de 16
...



k = 1 => conecta 2x com 2x+1
0(0) -> 1(1)
1(1) -> 0(0)
2(10) -> 3(11)
3(11) -> 2(10)
4(100) -> 5(101)
...

k = 2
0(0) -> 2(10)
1(1) -> 3(11)
2.
3.
4(100) -> 6(110)
5(101) -> 


100
101

*/
