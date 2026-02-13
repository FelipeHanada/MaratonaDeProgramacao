#include <bits/stdc++.h>
using namespace std;



/*
its guaranteed thar the blocks will form a
horizontal-lines pattern or vertical-lines pattern
we can check if any of this is possible
*/
void solve() {
    int w, h, a, b, x1, y1, x2, y2;
    cin >> w >> h >> a >> b >> x1 >> y1 >> x2 >> y2;

    if ((abs(x2-x1) >= a && abs(x2-x1) % a == 0)
        || (abs(y2-y1) >= b && abs(y2-y1) % b == 0)
    ) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
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