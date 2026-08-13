#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    ll tt; cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        string s; cin >> s;

        vector<vector<ll>> dp(n+5, vector<ll>(n+5, -1));
        // dp[i][j] = maior quantidade de penalidades possível onde o atual é i e existem j F's.
        dp[0][0] = 0;
        
        for (ll i=0; i<n; i++) {
            vector<vector<ll>> next(n+5, vector<ll>(n+5, -1));

            for (ll x=0; x<=n; x++) for (ll y=0; y<=n; y++) if (dp[x][y] != -1) {

                if (s[i] == 'T') {
                    next[min(y, x+1)][y] = max(next[min(y, x+1)][y], min(dp[x][y], x+1));
                    // ou usa a melhor solução colada na direita e toma 1 de penalidade
                    // ou continua usando a melhor solução geral e não ganha penalidade
                    // ou reseta a melhor solução colada na direita e toma y de penalidade

                } else if (s[i] == 'F') {
                    next[min(y+1, x)][y+1] = max(next[min(y+1, x)][y+1], min(x, dp[x][y] + 1));
                    // ou usa a melhor solução colada na direita e não ganha penalidade
                    // ou continua usando a melhor solução geral e toma 1 de penalidade
                    // ou reseta a melhor solução colada na direita e toma y+1 de penalidade
                } else {
                    next[min(y, x+1)][y] = max(next[min(y, x+1)][y], min(dp[x][y], x+1));
                    next[min(y+1, x)][y+1] = max(next[min(y+1, x)][y+1], min(x, dp[x][y] + 1));
                }

            }

            swap(dp, next);
        }

        ll ans = INT64_MIN;
        for (ll x=0; x<=n; x++) {
            for (ll y=0; y<=n; y++) if (dp[x][y] != -1) {
                ans = max(ans, dp[x][y]);
            }
        }

        cout << ans << '\n';
    }
}

/*
the solution is probably something like O(n^3)

we cant test for every possibility

if we know the config. we can find the best llerval in O(n)
    por uma mod. no alg. de kadane

] T T T T T F F F F F F vale a pena extender ou tomar 

cada estado tem:
melhor pontuação, melhor solução com o llervalo colado na direita, 

N N N T T N N N F N

para cada F fora do llervalo, é 1 erro
para cada T dentro do llervalo, é 1 erro

melhor pontuação, melhor pontuação colado na direita, q.t. de F's

*/