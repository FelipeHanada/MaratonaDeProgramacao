#include <bits/stdc++.h>
using namespace std;

/*
4^10 = 

n <= 1000
m <= 10
*/

constexpr int md = int(1e9) + 7;
inline int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

constexpr int N = (1 << 10);
int n, m;
array<int, N> dp, nextdp;

void substep(int mask, int i, int match) {
    if (i == n) {
        nextdp[match] = add(nextdp[match], dp[mask]);
        return;
    }

    if (mask & (1<<i)) {
        substep(mask, i + 1, match);
    } else {
        substep(mask, i + 1, match | (1 << i));
        if (i+1<n && !(mask & (1<<(i+1)))) substep(mask, i + 2, match);
    }
}

void step() {
    fill(nextdp.begin(), nextdp.end(), 0);
    for (int mask=0; mask < (1 << n); mask++) {
        substep(mask, 0, 0);
    }
    swap(dp, nextdp);
}

int main() {
    cin >> n >> m;

    fill(dp.begin(), dp.end(), 0);
    dp[0] = 1;

    for (int i=0; i<m; i++) {
        step();
    }

    cout << dp[0] << '\n';
}
