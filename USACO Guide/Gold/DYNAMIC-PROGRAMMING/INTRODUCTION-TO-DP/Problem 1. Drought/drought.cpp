#include <bits/stdc++.h>
using namespace std;

constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

constexpr int MAX_H = 1000;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> h(n);
    for (int i=0; i<n; i++) cin >> h[i];

    auto solve = [&](int c) -> int {
        for (int i=0; i<n; i++) if (c > h[i]) return 0;

        vector<int> dp(MAX_H+1, 1), next(MAX_H+1);
        for (int i=0; i<n; i++) {
            next[0] = dp[h[i]-c];
            for (int j=1; j<next.size(); j++) {
                next[j] = next[j-1];

                if (h[i]-j-c >= 0)
                    next[j] = add(next[j], dp[h[i]-j-c]);
            }

            swap(next, dp);
        }

        return dp[0];
    };

    int ans = 0;
    if (n & 1) {
        for (int c=0; c<=MAX_H; c++) ans = add(ans, solve(c));
    } else {
        ans = solve(0);
    }

    cout << ans << '\n';
}

/*
let dp[i][j] = quantidade de soluções que leram até o indice i
            e devem j jogadas (a posição i está com j+c)

dp[i][j] = sum( dp[i-1][] )


3
9 11 7


c = 2

0, 1, 2, 3, 4, 5, 6, 7 => 1

H-j




*/
