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
    deque<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    if (a.front() == -1) {
        if (a.back() == - 1) {
            a.back() = a.front() = 0;
        } else {
            a.front() = a.back();
        }
    }
    if (a.back() == -1) {
        a.back() = a.front();
    }

    for (int i=1; i<n-1; i++) {
        if (a[i] == -1) a[i] = 0;
    }

    cout << abs(a.back() - a.front()) << '\n';
    for (int x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}


int main() {
    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
