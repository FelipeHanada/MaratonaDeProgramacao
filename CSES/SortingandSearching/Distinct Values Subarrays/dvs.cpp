#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    set<int> window;
    int i=0, j=0;
    while (i < n) {
        while (j < n && !window.count(a[j])) {
            window.insert(a[j++]);
        }

        ans += j - i;
        window.erase(a[i++]);
    }

    cout << ans << '\n';
}