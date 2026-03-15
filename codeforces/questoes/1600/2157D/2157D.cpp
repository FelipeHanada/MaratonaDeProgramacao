#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        ll lp = 0, rp = 0;
        vector<pair<int,int>> L, R;
        for (int i=0; i<n; i++) {
            if (a[i] <= l) {
                lp += l - a[i];
                rp += r - a[i];
            } else if (a[i] >= r) {
                lp += a[i] - l;
                rp += a[i] - r;
            } else {
                L.push_back({a[i]-l, a[i]-r});
                R.push_back({l-a[i], r-a[i]});
            }
        }

        ll ans = 0;
        ans = max(ans, min(lp, rp));
        int i=0, j=L.size()-1;
        while (i <= j) {
            if (lp < rp) {
                lp += L[j].first;
                rp += L[j].second;
                j--;
            } else {
                lp += R[i].first;
                rp += R[i].second;
                i++;
            }
            ans = max(ans, min(lp, rp));
        }

        cout << ans << '\n';
    }
}