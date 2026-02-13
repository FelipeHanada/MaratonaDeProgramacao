#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 50000;
constexpr int K = 25;
int n, m;

int st[K+1][MAX_N];

int log2_floor(unsigned long long i) {
    return __builtin_clzll(1) - __builtin_clzll(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> st[0][i];
    }

    for (int j=1; j<=K; j++) {
        for (int i=0; i+(1<<j)-1<n; i++) {
            st[j][i] = max(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
    }

    int a, b;
    int ans = 0;
    while (m--) {
        cin >> a >> b;
        int k = log2_floor(b-a);
        if (st[0][a-1] == max(st[k][a-1], st[k][b-(1<<k)-1]))
            ans++;
    }

    cout << ans << '\n';
}
