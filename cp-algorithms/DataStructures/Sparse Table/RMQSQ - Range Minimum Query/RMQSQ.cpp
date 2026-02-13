#include <bits/stdc++.h>
using namespace std;



constexpr int MAX_N = 100000;
constexpr int K = 25;

int n, q;
int a[MAX_N];
int st[K+1][MAX_N];

int log2_floor(unsigned long long i) {
    return __builtin_clzll(1) - __builtin_clzll(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    copy(a, a+n, st[0]);
    for (int j=1; j<=K; j++) {
        for (int i=0; i + (1 << j) - 1 < n; i++) {
            st[j][i] = min(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
    }

    cin >> q;
    int i, j, k;
    while (q--) {
        cin >> i >> j;
        k = log2_floor(j-i+1);
        cout << min(st[k][i], st[k][j-(1<<k)+1]) << '\n';
    }
}
