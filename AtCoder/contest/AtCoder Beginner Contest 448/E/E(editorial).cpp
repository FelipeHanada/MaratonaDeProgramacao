#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int add(int a, int b, int md) {
    a += b;
    if (a > md) a -= md;
    return a;
}

int mult(int a, int b, int md) {
    return ((ll)a * b) % md;
}

int main() {
    constexpr int N = int(1e6);

    int k, m;
    cin >> k >> m;
    vector<pair<int, int>> a(k);
    for (int i=0; i<k; i++) cin >> a[i].first >> a[i].second;

    auto get_nmod = [&](int md) -> int {
        array<array<int,N>,10> d;
        fill(d[0].begin(), d[0].end(), 0);
        for (int i=1; i<=9; i++) {
            d[i][0] = 0;
            for (int j=1; j<N; j++) {
                d[i][j] = add(mult(d[i][j-1], 10, md), i, md);
            }
        }

        array<int,N> p10;
        p10[0] = 1;
        for (int i=1; i<N; i++) p10[i] = mult(p10[i-1], 10, md);
        int nmod = 0;
        for (int i=0; i<k; i++) {
            while (a[i].second) {
                int delta = min(N-1, a[i].second);
                nmod = add(mult(nmod, p10[delta], md), d[a[i].first][delta], md);
                a[i].second -= delta;
            }
        }
        return nmod;
    };


    cout << ((get_nmod(m*10007) - get_nmod(m) + 10007*m) % (10007*m)) / m << '\n';
}
