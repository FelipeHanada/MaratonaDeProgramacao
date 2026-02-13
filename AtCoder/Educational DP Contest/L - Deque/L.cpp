#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 3000;
int n;
int a[MAX_N];
ll dp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

ll go(int i, int j) {
    if (i + j == n) return 0;
    if (visited[i][j]) return dp[i][j];

    ll left = go(i+1, j) + a[i] * ((i+j)%2 ? -1 : 1);
    ll right = go(i, j+1) + a[n-1-j] * ((i+j)%2 ? -1 : 1);
    dp[i][j] = ((i+j)%2 ? min(left, right) : max(left, right));
    visited[i][j] = true;
    return dp[i][j];
}


int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<MAX_N; i++) {
        fill_n(visited[i], MAX_N, false);
    }

    cout << go(0, 0) << '\n';
}