#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    multiset<int> s;
    for (int i=1; i<=n; i++) s.insert(i);
    deque<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (s.count(a[i])) s.erase(a[i]);
    }

    int choices[3];
    if (s.size() == 0) {
        choices[0] = a[0];
        choices[1] = a[1];
        choices[2] = a[2];
    } else {
        choices[0] = *s.begin();
        choices[2] = a.back();
        for (int i=1; i<=n; i++) {
            if (i != choices[0] && i != choices[2]) {
                choices[1] = i;
                break;
            }
        }
    }

    for (int i=0; i<k; i++) {
        cout << choices[i % 3] << ' ';
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