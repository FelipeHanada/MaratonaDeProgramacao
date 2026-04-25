#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define f first
#define s second
using ll = long long;

constexpr int md = 998244353;

/*
6 4
A = 1 6 9 2 3 1
B = 1 10 3 7

j = 1, tudo dá 0

j = 2, bj   0 bj 0 ...

j = 3, bj 2bj  0 bj 2bj 0

j = 4, bj 2bj 3bj



*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];


}
