#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    int zero = 0, one = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x == 0) zero++;
        if (x == 1) one++;
    }

    if (!zero) cout << "No";
    else if (zero == 1) cout << (zero < n ? "Yes" : "No");
    else if (one) cout << "Yes";
    else cout << "No";
    cout << '\n';
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
