#include <bits/stdc++.h>
using namespace std;

/*
after we choose an l and r, the number of elements c after the operation is
count(1, n, c) - count(l, r, c) + count(l, r, x)

to maximize the number of elements c we may maximize count(l, r, x) - count(l, r, c)

let dp[i][x] be the max numbers that can be converted to c until r = i
therefore
    dp[i][x] = max : count(1, i, c) - count(l, r, c) + count(l, r, x) until r = i
    then dp[i][x] - count(1, i, c) is the maximum value that we are searching for

dp[0][x] = 0  there is no array
when a[i] = x != c
    dp[i][x] = max(count(1, i, c)*, dp[i-1][x]**) + 1
                *  start a new interval with l = i
                ** increment the last interval with another element
*/

int n, c;
int dp[500001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;

    int count_c = 0;
    int mx = 0;
    for(int i=0; i<n; i++) {
        int ai; cin >> ai;
        if (ai == c) count_c++;
        else {
            dp[ai] = max(count_c, dp[ai]) + 1;
            mx = max(mx, dp[ai] - count_c);
        }
    }

    cout << count_c + mx << "\n";
}
