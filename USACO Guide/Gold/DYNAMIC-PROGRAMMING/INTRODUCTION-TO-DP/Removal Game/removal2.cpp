#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MAX_N = 5000;
int n;
int a[MAX_N];
ll dp1[MAX_N][MAX_N]; // best sum for the first player on subarray i..j
ll dp2[MAX_N][MAX_N]; // best sum for the second player on subarray i..j

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<n; i++) {
        dp1[i][i] = a[i];
        dp2[i][i] = 0;
    }

    for (int s=1; s<n; s++) {
        for (int i=0; i+s<n; i++) {
            int j = i+s;

            ll l = a[i] + dp2[i+1][j], r = a[j] + dp2[i][j-1];
            if (l > r) {
                dp1[i][j] = l;
                dp2[i][j] = dp1[i+1][j];
            } else {
                dp1[i][j] = r;
                dp2[i][j] = dp1[i][j-1];
            }
        }
    }

    cout << dp1[0][n-1] << '\n';
}
