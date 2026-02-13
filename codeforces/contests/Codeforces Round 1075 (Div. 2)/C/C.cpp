#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;

    if (__builtin_popcount(n) == 1) {
        cout << "-1\n";
        return;
    }

    if (n % 2) {
        cout << n/2*2 << ' ';
        for (int i=2; i<=n-1; i++) {
            if (i % 2) {
                cout << i - 1 << ' ';
            } else {
                cout << i + 1 << ' ';
            }
        }
        cout << "1\n";
    } else {
        set<int> s;
        for (int i=1; i<=n; i++) s.insert(i);
        int target = 1<<__builtin_ctz(n);

        vector<int> ans(n+1, -1);
        ans[target] = n;
        for (int i=2; i<n; i++) {
            if (i % 2) {
                ans[i] = i - 1;
            } else {
                if (ans[i] != -1) {
                    ans[1] = i + 1;
                    continue;
                }
                ans[i] = i + 1;
            }
        }
        ans[n] = 1;
        for (int i=1; i<=n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
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
