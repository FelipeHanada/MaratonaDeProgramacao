#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<bool>> comp(n, vector<bool>(n, false));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int x; cin >> x;
            comp[i][j] = x;
        }
    }

    vector<int> dp(1<<n, 0);
    dp[0] = 1;
    for (int s=1; s<n; s++) if (__builtin_popcount(s) == 2*__builtin_popcount(s >> (n/2))) {
        
    }
}