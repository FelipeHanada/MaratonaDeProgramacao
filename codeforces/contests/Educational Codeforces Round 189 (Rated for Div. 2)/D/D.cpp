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
00000001        1
00000010        2
00000011        3
------------------------
00000100        4
00000101        5       5^6^7 => 4
00000110        6       6^7 => 1
00000111        7       7 => 7
------------------------
00001000        8
00001001        9       9^...^15 => 8
00001010        10      10^...^15 => 1
00001011        11      11^...^15 => 11
00001100        12      12^...^15 => 7
00001101        13      13^14^15 => 10
00001110        14      14^15 => 1
00001111        15      15 => 15
------------------------

xor (0..2^i-1) = 0 (i>1)
xor (2^i .. 2^(i+1)-1) = 0    (i>1)
*/

vector<ll> xor0;
void precompute() {
    xor0.push_back(0);
    for (ll x = 4; x <= ll(1e18); x <<= 1) {
        xor0.push_back(x-1);
    }
}

void solve() {
    ll n, x;
    cin >> n >> x;

    auto l = upper_bound(xor0.begin(), xor0.end(), x);
    auto r = upper_bound(xor0.begin(), xor0.end(), n);

    int a = distance(xor0.begin(), l);
    int b = distance(l, r);
    cout << mult(a, b) << '\n';
}

int main() {
    precompute();

    int tt;
    cin >> tt;
    while (tt--) solve();
}
