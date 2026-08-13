#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    map<int, int> cnt;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    int curr = 0;
    array<int,3> ans = { 0, 0, 0 };
    int l = 0, r = 0;
    while (r < n) {
        while (r < n && (curr < k || cnt[a[r]] > 0)) {
            if (!(cnt[a[r]]++)) curr++;
            r++;
        }

        ans = max(ans, {r - l, l, r});

        if (!(--cnt[a[l]])) curr--;
        l++;
    }

    cout << ans[1] + 1 << ' ' << ans[2] << '\n';
}
