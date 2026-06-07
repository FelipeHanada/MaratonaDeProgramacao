#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr int md = 998244353;
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
inline int mult(int a, int b) {
    return ((ll)a * b) % md;
}


/*
let dp1(i) = numbers of ways to run the proc.
                s.t. vertex i belongs to S
let dp2(i) = numbers of ways to run the proc.
                s.t. vertex i DOES NOT belong to S




*/
void solve() {

}

int main() {
    int tt;
    cin >> tt;
    while (tt--) solve();
}
