#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define _1 first
#define _2 second
#define ll long long

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    deque<int> a(n), p(n+1);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }

    vector<int> prefix(n), suffix(n);
    prefix.front() = a.front();
    suffix.back() = a.back();
    for (int i=1; i<n; i++) prefix[i] = min(prefix[i-1], a[i]);
    for (int i=n-2; i>=0; i--) suffix[i] = max(suffix[i+1], a[i]);

    bool ok = true;
    for (int i=0; ok && i<n-1; i++) {
        if (prefix[i] < suffix[i+1]) {
        } else {
            ok = false;
        }
    }

    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}


int main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
