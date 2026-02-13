#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int even=0, odd=0;
    deque<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            odd++;
        } else {
            even++;
        }
    }

    if (even && odd) {
        sort(a.begin(), a.end());
    }

    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
