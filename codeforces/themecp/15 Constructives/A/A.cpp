#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int clog10(int x) {
    int i = 0;
    while (x) {
        x /= 10;
        i++;
    }
    // log 9 = 1
    // 10 -> 2
    return i;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;

        int x = 1, y = 1;
        for (int i=0; i<c-1; i++) {
            x *= 10;
            y *= 10;
        }

        while (clog10(x) < a) x *= 3;
        while (clog10(y) < b) y *= 7;
        cout << x << ' ' << y << '\n';
    }
}