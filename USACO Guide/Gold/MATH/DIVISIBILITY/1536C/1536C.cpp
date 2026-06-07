#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n; string s;
        cin >> n >> s;

        map<pair<int, int>, int> dp;
        int d = 0, k = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == 'D') d++;
            else k++;

            int g = __gcd(d, k);
            cout << ++dp[{ d/g, k/g }] << ' ';
        }
        cout << '\n';
    }
}