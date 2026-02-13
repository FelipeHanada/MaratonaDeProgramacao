#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    for (int l=1; l<n; l++) {
        for (int r=l+1; r<n; r++) {
            int s1, s2, s3;
            s1 = (prefix[l]) % 3;
            s2 = (prefix[r] - prefix[l]) % 3;
            s3 = (prefix[n] - prefix[r]) % 3;
            if (s1 == s2 && s2 == s3) {
                cout << l << ' ' << r << '\n';
                return;
            } else if (s1 != s2 && s2 != s3 && s1 != s3) {
                cout << l << ' ' << r << '\n';
                return;
            }
        }
    }

    cout << "0 0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
