#include <bits/stdc++.h>
using namespace std;


/*
let a permutation P where P[i] = x
find(x) is always not UNDEFINED iff.
1) there is no P[j] > x with j < x  (eq. there is no bigger number on the left)
2) there is no P[j] < x with j > x  (eq. there is no smaller number on the right)


5
10100
-> 1 (2-5)
-> (1-2) 3 (4-5)

greedy strategy:
    1. fix all the 1's indices
    2. fill the rest satisfying the fixed indices and in inverse order
    3. check if it does satisfies the problem
*/

void solve() {
    int n;
    cin >> n;

    bool valid = true;
    bool last  = true;
    bool alast  = true;
    int last_fixed = -1;
    vector<int> ans(n, -1);
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        if (c == '1') {
            for (int j=1; j+last_fixed<i; j++) {
                ans[j+last_fixed] = i-j+1;
            }
            last_fixed = i;
            ans[i] = i+1;
            if (!last && alast) valid = false;
        }
        alast = last;
        last = (c == '1');
    }
    for (int j=1; j+last_fixed<n; j++) {
        ans[j+last_fixed] = n-j+1;
    }
    if (!last && alast) valid = false;
    if (!valid) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << '\n';
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
