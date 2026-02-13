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
    deque<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    int count = 0;
    int last = 0;
    for (int i=0; i<n; i++) {
        if (a[i] ^ b[i]) {
            count++;
            last = i % 2;
        }
    }

    if (count % 2) {
        if (last) {
            cout << "Mai\n";
        } else {
            cout << "Ajisai\n";
        }
    } else {
        cout << "Tie\n";
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
