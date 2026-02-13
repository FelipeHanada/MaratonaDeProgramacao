#include <bits/stdc++.h>
using namespace std;


/*
. R R . => x x-1
. R L . => x x
. L R . => x x
. L L . => x x+1
*/

void solve() {
    int n;
    cin >> n;

    bool a = true, b = true;
    int countA = 1, countB = 1;
    char lastA = 'R', lastB = 'L';
    int x;
    int first, last;
    cin >> first;
    last = first;
    for (int i=1; i<n; i++) {
        cin >> x;
        if (last - 1 == x) {
            if (lastA != 'R') a = false;
            if (lastB != 'R') b = false;
        } else if (last + 1 == x) {
            if (lastA != 'L') a = false;
            if (lastB != 'L') b = false;
        } else if (last == x) {
            lastA = 'R' + 'L' - lastA;
            lastB = 'R' + 'L' - lastB;
        } else {
            a = b = false;
        }
        if (lastA == 'R') countA++;
        if (lastB == 'R') countB++;
        last = x;
    }

    int ans = 0;
    if (a && countA == first) ans++;
    if (b && countB == first) ans++;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}