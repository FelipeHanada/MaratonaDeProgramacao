#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
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

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    set<int> s;
    while (m--) {
        int l, r;
        cin >> l >> r; r++;

        if (s.count(l)) s.erase(l);
        else s.insert(l);
        if (s.count(r)) s.erase(r);
        else s.insert(r);
    }

    vector<int> a;
    a.push_back(0);
    for (int x : s) a.push_back(x);

    while (q--) {
        int l, r; cin >> l >> r;
        auto l = 
    }
}

/*
[101000000010001010111111111100000]
=> 11111111111111100000
    (2^(quantidade de 1's) - 1) << (quantidade de zeros)

*/
