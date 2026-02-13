#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) { 
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i=0; i<(n+1)/2; i++) {
            cout << i+1 << ' ' << 2*(n-i) << '\n';
        }
        for (int i=0; i<n/2; i++) {
            cout << (n+1)/2+i+1 << ' ' << 2*(n-i)-1 << '\n';
        }
    }
}

/*
1 2n        => 2n+1
2 2n-2      => 2n
3 2n-1      => 2n+2

1 2 3 4 5 | 6 7 8 9 10
1 | 2
X X 3 | X 5 X
X X X 4 5 | X 7 X 9 X

*/
