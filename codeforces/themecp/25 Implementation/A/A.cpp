#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> a(c);
    for (int i=0; i<c; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int next = k;
    int j = 0;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (i == next || (j < c && i == a[j])) {
            next = i + k;
            ans++;
        }

        while (j < c && i == a[j]) j++;
    }
    cout << ans << '\n';
}
