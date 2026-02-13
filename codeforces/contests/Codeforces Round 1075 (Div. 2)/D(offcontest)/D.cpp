#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

constexpr int MOD = 1e9 + 7;

/*
if w_1 = 0 or w_n = 0, its impossible to construct such perm.
    (we can take just 0 or the entire array)

we can construct all permutations starting from [0] and
    adding the next number until there are 0 to n-1

for any k in the permutation
    there is no mex = k iff. there are k'<k and k"<k
        both left and right from k position in the permutation


(0, 1, 2)

when adding k,
    if w_k = 0, we can insert k - 1 into any position except the borders
    if w_k = 1, we can insert k only in the borders
*/

void solve() {
    int n, c;
    cin >> n >> c;
    string s;
    cin >> s;

    if (s[0] == '0' || s.back() == '0') {
        cout << "-1\n";
        return;
    }

    int ans = 1;
    for (int i=0; i<n-1; i++) {
        int k;
        if (s[i] == '1') k = 2;
        else k = i;
        c /= __gcd(c, k);
        ans = ((ll) ans * k) % MOD;
    }

    if (c == 1) {
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
