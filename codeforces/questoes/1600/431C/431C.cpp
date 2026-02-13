#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9+7;


int main() {
    int n, k, d;
    cin >> n >> k >> d;

    // dp[i][j] = quantidade de caminhos que somam exatamente n
    // de modo que j=0 se nenhuma aresta de tamanho pelo menos d foi utilizada
    //           e j=1 se alguma aresta de tamanho pelo menos d foi utilizada
    
    vector<int> dp0(n+1, 0);
    vector<int> dp1(n+1, 0);
    dp0[0] = 1;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<d && i-j >= 0; j++) {
            dp0[i] = (dp0[i] + dp0[i-j]) % MOD;
            dp1[i] = (dp1[i] + dp1[i-j]) % MOD;
        }
        for (int j=d; j<=k && i-j>=0; j++) {
            dp1[i] = (dp1[i] + dp0[i-j]) % MOD;
            dp1[i] = (dp1[i] + dp1[i-j]) % MOD;
        }
    }

    cout << dp1[n] << '\n';
}
