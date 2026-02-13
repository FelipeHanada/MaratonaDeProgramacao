#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    map<int, int> window;
    int i=0, j=0;
    while (i < n) {
        while (j < n && window.size() <= k) {
            window[a[j]]++;
            j++;
        }

        ans += j - i - 1 + (int)(window.size() <= k);

        if (!--window[a[i]]) {
            window.erase(a[i]);
        }
        i++;
    }

    cout << ans << '\n';
}
