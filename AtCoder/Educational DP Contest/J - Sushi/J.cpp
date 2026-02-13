#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    int a[3] = {0, 0, 0};
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[x-1]++;
    }

    double dp[a[0]+a[1]+a[2]+1][a[1]+a[2]+1][a[2]+1];
    for (int k=0; k<=a[2]; k++) {
        for (int j=0; j<=a[1]+a[2] && j+k<=n; j++) {
                for (int i=0; i<=a[0]+a[1]+a[2] && i+j+k<=n; i++) {
                // E(i,j,k) = i/n*(1+E(i-1,j,k)) + j/n*(1+E(i+1,j-1,k)) + k/n*(1+E(i,j+1,k-1)) + (n-i-j-k)/n*(1+E(i,j,k))
                // E(i,j,k) - (n-i-j-k)/n*(1+E(i,j,k)) = i/n*(1+E(i-1,j,k)) + j/n*(1+E(i+1,j-1,k)) + k/n*(1+E(i,j+1,k-1))
                // (n-(n-i-j-k))/n*(E(i,j,k))-(n-i-j-k)/n = i/n*(1+E(i-1,j,k)) + j/n*(1+E(i+1,j-1,k)) + k/n*(1+E(i,j+1,k-1))
                // (i+j+k)/n*E(i,j,k) = i/n*(1+E(i-1,j,k)) + j/n*(1+E(i+1,j-1,k)) + k/n*(1+E(i,j+1,k-1)) + (n-i-j-k)/n
                // E(i,j,k) = [i/n*(1+E(i-1,j,k)) + j/n*(1+E(i+1,j-1,k)) + k/n*(1+E(i,j+1,k-1)) + (n-i-j-k)/n]*n/(i+j+k)
                // E(i,j,k) = [i*(1+E(i-1,j,k)) + j*(1+E(i+1,j-1,k)) + k*(1+E(i,j+1,k-1)) + (n-i-j-k)]/(i+j+k)

                dp[i][j][k] = 0;
                if (i+j+k == 0) continue;

                if (i) dp[i][j][k] += i*(1+dp[i-1][j][k]);
                if (j) dp[i][j][k] += j*(1+dp[i+1][j-1][k]);
                if (k) dp[i][j][k] += k*(1+dp[i][j+1][k-1]);
                dp[i][j][k] += (n-i-j-k);
                dp[i][j][k] /= i+j+k;
            }
        }
    }

    cout << setprecision(9) << fixed << dp[a[0]][a[1]][a[2]] << '\n';
}
