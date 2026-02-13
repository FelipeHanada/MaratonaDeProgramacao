/*
preços de casa

9
1 2 3 4 5 6 7 8 9
C V C           V

9
9 8 7 6 5 4 3 2 1

9



dp[i][j] = melhor lucro até o mes i
	j = 0, não comprou
	j = 1, primeira compra
	j = 2, primeira venda
	j = 3, segunda compra
	j = 4, segunda venda

lucro no mes i = soma de todas as vendas
		- soma de todas as compras

dp[i][0] = 0
dp[0][1] = INT32_MIN
dp[0][2] = INT32_MIN
dp[0][3] = INT32_MIN
dp[0][4] = INT32_MIN

j = {1,3} - compra
dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - a[i])

j = {2,4} - venda
dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + a[i])

ans = dp[n-1][4]

O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector dp(5, vector<int>(n+1, INT32_MIN));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (int i=1; i<=4; i++) {
        for (int j=i; j<=n; j++) {
            if (i % 2) {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] - a[j-1]);
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + a[j-1]);
            }
        }
    }

    cout << max(0, max(dp[2][n], dp[4][n])) << '\n';
}
