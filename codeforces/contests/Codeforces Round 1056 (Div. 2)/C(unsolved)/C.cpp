#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int lastL = 0, lastR = 1;
    int countL = 0, countR = 0;
    for (int i=1; i<n; i++) {
        if (a[i-1] == a[i]) { // trocou
            if (lastL == 0) countL++;
            if (lastR == 0) countR++;
            if (lastL >= 0) lastL = 1 - lastL;
            if (lastR >= 0) lastR = 1 - lastR;
        } else if (a[i-1] + 1 == a[i]) {
            // aumentou -> L L
            if (lastL == 1) lastL = -1;
            if (lastR == 1) lastR = -1;
        } else if (a[i-1] - 1 == a[i]) {
            // diminuiu
            if (lastL == 0) lastL = -1;
            if (lastR == 0) lastR = -1;
            countL++;
            countR++;
        } else {
            lastL = lastR = -1;
        }
    }

    int ans = 0;
    if (lastL >= 0 && countL+1 == a[0]) ans++;
    if (lastR >= 0 && countR+1 == a[0]) ans++;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
