#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;


int main() { _
    int n;
    cin >> n;
    map<int, int> cnt;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        for (int j=1; j<31; j++) {
            ans += cnt[(1<<j)-x];
        }
        cnt[x]++;
    }

    cout << ans << '\n';
}
