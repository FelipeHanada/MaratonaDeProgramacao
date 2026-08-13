#include <bits/stdc++.h>
using namespace std;
using ll = long  long;

constexpr int md = 998244353;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % md; }
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
int inv(int a) { return binpow(a, md-2); }


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i=1; i<=n; i++) prefix[i] = add(prefix[i-1], a[i-1]);

    int ans = 0;
    int sum = 0;
    for (int i=0; i<n/2; i++) {
        sum = add(sum, sub(prefix[n-i], prefix[i]));
        ans = add(ans, mult(sum, inv(i+1)));
        ans = add(ans, mult(sum, inv(n-i)));
    }

    if (n & 1) {
        sum = add(sum, a[n/2]);
        ans = add(ans, mult(sum, inv(n/2+1)));
    }

    cout << ans << '\n';
}

/*

soma de todos os intervalos de tamanho 1 / 1
    todos os elementos são contados 1

soma de todos os intervalos de tamanho 2 / 2
    todos os elementos são contados 2 (exceto as pontas)

soma de todos os intervalos de tamanho 3 / 3
    todos os elementos são contados 3 (exceto os dois primeiros/ultimos)
    os segundos e penultimos são contados 2 vezes
    as pontas apenas 1

...
soma de todos os intervalos de tamanho n-1 / n-1
soma de todos os intervalos de tamanho n / n


1 2 3 4 5 6 7 8 9 10
1 1 1 1 1 1 1 1 1 1
1 2 2 2 2 2 2 2 2 1
1 2 3 3 3 3 3 3 2 1
1 2 3 4 4 4 4 3 2 1
1 2 3 4 5 5 4 3 2 1

1 2 3 4 5 6 7 8 9
1 1 1 1 1 1 1 1 1
1 2 2 2 2 2 2 2 1
1 2 3 3 3 3 3 2 1
1 2 3 4 4 4 3 2 1
1 2 3 4 5 4 3 2 1


9
3 1 4 1 5 9 2 6 5


*/
