#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define f first
#define s second

int n, m;

void solve() {
    cin >> n >> m;
    if (n > 1 && m > 1 && (n >= 3 || m >= 3)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int i=0; i<t; i++) {
        solve();
    }
}