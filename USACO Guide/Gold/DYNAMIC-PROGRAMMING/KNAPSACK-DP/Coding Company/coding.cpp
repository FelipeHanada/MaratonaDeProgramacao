#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9+7;
constexpr int MAX_X = 5000;
constexpr int MAX_N = 100;
int dp1[MAX_N+1][MAX_X*2+1];
int dp2[MAX_N+1][MAX_X*2+1];

#define ll long long

// dp[i][j][k] = 
// quantidade de formas de agrupar até o i-ésimo coder
// com j grupos e penalty k

// 1. criar um novo grupo
// 2. adicionar em um grupo
// 3. finalizar um grupo

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> t(n);
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
   
    for (int j=0; j<=n; j++) {
        fill_n(dp1[j], MAX_X*2+1, 0);
        fill_n(dp2[j], MAX_X*2+1, 0);
    }
    dp1[0][MAX_X] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            for (int k=0; k<2*MAX_X+1; k++) {
                if (!dp1[j][k]) continue;

                // adicionar como grupo individual
                dp2[j][k] = (dp2[j][k] + dp1[j][k]) % MOD;

                // criar um grupo novo
                if (j < n)
                    dp2[j+1][k - t[i-1]] = (dp2[j+1][k - t[i-1]] + dp1[j][k]) % MOD;

                // adicionar em um grupo aberto
                if (j > 0)
                    dp2[j][k] = (dp2[j][k] + ((ll)j * dp1[j][k]) % MOD) % MOD;

                // finalizar um grupo aberto
                if (j > 0)
                    dp2[j-1][k + t[i-1]] = (dp2[j-1][k + t[i-1]] + ((ll)j * dp1[j][k]) % MOD) % MOD;
            }
        }

        for (int j=0; j<=n; j++) {
            for (int k=0; k<2*MAX_X+1; k++) {
                dp1[j][k] = dp2[j][k];
            }
            fill_n(dp2[j], 2*MAX_X+1, 0);
        }

        // for (int j=0; j<=n; j++) {
        //     for (int k=MAX_X-x-3; k<=MAX_X+x+3; k++) {
        //         cout << dp[i][j][k] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    int ans = 0;
    for (int k=MAX_X; k<=MAX_X+x; k++) {
        ans = (ans + dp1[0][k]) % MOD;
    }
    cout << ans << '\n';
}
