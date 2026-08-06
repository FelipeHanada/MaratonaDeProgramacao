#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);





int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; ll x; cin >> n >> x;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        ll k = a[n-1];
        for (int i=n-2; i>=0; i--) {
            if (a[i] <= k) k = a[i];
        }

        ll ans = (x/a[0]) * ((a[0] + k - 1)/k);

        auto check = [&](ll xx) -> bool {
            return (xx + 1) * (x / k) <= x;
        };
        ll l = 0, r = INT32_MAX;
        if (check(l)) {
            while (r - l > 1) {
                ll mid = (l + r) / 2;
                if (check(mid)) l = mid;
                else r = mid;
            }

            ans += (l / k) + 1;
        }

        cout << ans << '\n';
    }
}

/*
{ 0, 2, 4 }


X mod 5 mod 6

X = 18
X mod 5 = 3


X mod A mod B = 0
somente quando X mod A é multiplo de B


((X mod 5) mod 2) mod 3 = 0

(X mod 5) mod 2 é múltiplo de 3
    => X mod 5 = 0




9 8 2 4 3 5 3

(((X mod ...) mod 3) mod 5) mod 3

((X mod ...) mod 3) mod 5) é múltiplo de 3
=> ((X mod ...) mod 3) mod 5) = 0
   ((X mod ...) mod 3) mod 5) = 3

   ((X mod ...) mod 3) mod 5) = 0
   (X mod ...) mod 3 é múltiplo de 5



X é múltiplo de A1
ou X mod A1 é múltiplo de A2
ou X mod A1 mod A2 é múltiplo de A3
...


a densidade de X é uniforme em [1, X]
a densidade de X mod A1 está em [0, A1-1]



ideia: ir do mod de fora para o mod de dentro

Y = (X mod ...)
Y mod Ai = Zi

onde Z = {Zi} é um conjunto de resultados bons



9 8 2 4 3 5 3

X [9 8 2 4 3 5] mod 3 = 0

X [9 8 2 4 3] mod 5 = {0, 3}

X [9 8 2 4] mod 3 = 0

X [9 8 2] mod 4 = {0, 3}

X [9 8] mod 2 = {0}

X [9] mod 8 = {0, 2, 4, 6} (k = 2)

X mod 9 = { 0, 2, 4, 6, 8 } (k = 2)


9 31415
9 9 8 2 4 4 3 5 3
=> 17452

31415



3490 + 3490 + 3490 + 3490

*/


