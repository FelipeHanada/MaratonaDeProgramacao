#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;
constexpr int md = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) {
    return ((ll)a * b) % md;
}

/*

let prefix[x] = xor ( 1 .. x )

the answer is the number of pairs (l, r) such that
    0 <= l <= x <= r <= n 
    and prefix[l-1] = prefix[r]


for a given x
    prefix[x] = xor ( 2^i .. x ) for the any i > 1
        such that 2^i < x



dá pra computar o número de pares (l, r) tal que 
    0 <= l <= r <= n 
    e prefix[l-1] = prefix[r]
    usando DP?


Seja f(n) = quantidade de pares (l, r) (l <= r <= n) que satisfazem
se eu conseguir computar f(n) rapidamente
    então eu consigo dar a resposta do problema?
    ans = 


*/

void solve() {
    ll n, x;
    cin >> n >> x;

}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
}
