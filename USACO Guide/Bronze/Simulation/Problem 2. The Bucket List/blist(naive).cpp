#include <bits/stdc++.h>
using namespace std;


int cows[100][3];
int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }

    int ans = 0;
    int buckets = 0;
    for (int t=1; t<=1000; t++) {
        for (int i=0; i<n; i++) {
            if (cows[i][0] == t) {
                buckets += cows[i][2];
            }
        }

        for (int i=0; i<n; i++) {
            if (cows[i][1] == t) {
                buckets -= cows[i][2];
            }
        }

        ans = max(ans, buckets);
    }

    cout << ans << '\n';
}