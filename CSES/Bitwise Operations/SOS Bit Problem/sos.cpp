#include <bits/stdc++.h>
using namespace std;


constexpr int N = 20;
int inv(int x) { return ((1<<N)-1)^x; }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> F(1<<N, 0), invF(1<<N, 0);
    for (int i=0; i<n; i++) F[a[i]]++;
    for (int i=0; i<N; i++) for (int mask = 0; mask < (1<<N); mask++)
        if (mask & (1<<i)) F[mask] += F[mask^(1<<i)];

    for (int i=0; i<n; i++) invF[inv(a[i])]++;
    for (int i=0; i<N; i++) for (int mask = 0; mask < (1<<N); mask++)
        if (mask & (1<<i)) invF[mask] += invF[mask^(1<<i)];

    for (int x : a) {
        cout << F[x] << ' '
            << invF[inv(x)] << ' '
            << n - F[inv(x)] << '\n';
    }
}

/*
para cada x:
1. quantos y t.q. x | y = x (y é subset de x)
    problema clássico de SOS
    => F[x]
2. quantos y t.q. x & y = x (x é subset de y)
    se a gente tomar o complemento de x (~x) e y (~y)
    temos que ~y é subset de ~x
    basta rodar SOS para ~a
    => invF[~x]
3. quantos y t.q. x & y != 0
    considere x & y = 0
    então y é subset de ~x
    => n - F[~x]
*/
