#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n;
    cin >> n;
    int big = 0;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        big = max(big, a[i]);
    }

    int ans = 1;
    for (int i=0; i<n; i++) {
        if (a[i] != big) continue;
        int j = i;
        int curr = 0;
        for (; j<n && a[j] == a[i]; j++) {
            curr++;
        }
        i = j - 1;
        ans = max(ans, curr);
    }

    cout << ans << '\n';
}