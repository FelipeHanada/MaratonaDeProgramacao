#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define f first
#define s second

/*
if a/m <= b, we can move the mouse to the last tab and close everything until the condition is false

a/m <= b => ans = 2
a/m > b => ans = 1

*/

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    if (b >= a || a/n >= b) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
