#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int p, q, x, y;
    cin >> p >> q >> x >> y;
    cout << ((x >= p && x < p+100 && y>=q && y < q+100) ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();    
    return 0;
}
