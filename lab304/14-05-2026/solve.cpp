#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    auto contar = [&](int k) -> int {
        // retorna a quantidade de haybales no intervalo [0, k)
        if (a[0] >= k) return 0;

        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid] < k) l = mid;
            else r = mid;
        }
        return r;
    };

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << contar(b + 1) - contar(a) << '\n';
    }
}

/*
Quantidade de haybales no intervalo fechado [a, b]
    é dado pela quantidade de haybales no intervalo [0, b] - [0, a)
                                                    = [0, b+1) - [0, a)


*/

