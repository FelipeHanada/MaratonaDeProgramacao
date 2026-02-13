#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
4
4 0 = 0&3 + 1&2
00 
01
10
11

0000 1
0001 2
0010 1
0011 
0100 
0101 2
0110 X
0111 X

1110

7&1 + 

4 1 = 0&2 + 1&3


4 2 = 0&1 + 1&3

4 3
*/

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;

        if (n == 4 && k == 3) {
            cout << "-1\n";
            continue;
        }

        if (n - 1 == k) {
            cout << n-1 << ' ' << n-2 << '\n';
            cout << "0 2\n";
            cout << "1 " << n-3 << '\n';
            for (int i=3; i<n/2; i++) {
                cout << i << ' ' << n-1-i << '\n';
            }
            continue;
        }

        cout << k << ' ' << n-1 << '\n';
        if (k != 0) cout << "0 " << n-1-k << '\n';
        for (int i=1; i<n/2; i++) {
            if (i == k || i == n-1-k) continue;
            cout << i << ' ' << n-1-i << '\n';
        }
    }
}