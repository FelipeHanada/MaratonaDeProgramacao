#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int n;
    cin >> n;
    vector<char> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans1, ans2;

    ans1 = 0;
    int j = 0;
    for (int i=0; i<n; i++) {
        while (j < n && a[i] > b[j]) j++;
        if (j == n) {
            ans1++;
        } else {
            j++;
        }
    }

    ans2 = 0;
    j = 0;
    for (int i=0; i<n; i++) {
        while (j < n && a[i] >= b[j]) j++;
        if (j < n) {
            ans2++;
            j++;
        }
    }

    cout << ans1 << '\n';
    cout << ans2 << '\n';
}
