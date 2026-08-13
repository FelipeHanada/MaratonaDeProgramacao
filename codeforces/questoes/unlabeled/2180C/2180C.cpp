#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> ans(k, 0);
        int loose = 0;

        for (int i=31; i>=0; i--) {
            if (n & (1<<i)) {
                // need odd number of set bits
                // we can use all numbers to set
                // its always optimal to leave the unset bits to tight numbers

                if (k & 1) {
                    for (int j=0; j<k; j++) ans[j] |= (1<<i);
                } else {

                    if (loose == k) {
                        for (int j=0; j<k-1; j++) ans[j] |= (1<<i);
                    } else {
                        for (int j=0; j<loose; j++) ans[j] |= (1<<i);
                        for (int j=loose+1; j<k; j++) ans[j] |= (1<<i);
                        loose++;
                    }
                }

            } else {
                // need even number of set bits
                // we can only use the loose numbers to set
                for (int j=0; j+1<loose; j+=2) {
                    ans[j] |= (1<<i);
                    ans[j+1] |= (1<<i);
                }
            }
        }


        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}
