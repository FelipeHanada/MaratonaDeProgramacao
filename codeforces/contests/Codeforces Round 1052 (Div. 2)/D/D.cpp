#include <bits/stdc++.h>
using namespace std;


/*
0:  0000
1:  0001
2:  0010
3:  0011
4:  0100
5:  0101
6:  0110
7:  0111
8:  1000
9:  1001
10: 1010

1111 - 1010 = 

0 1 2 3 4 5 6 7 8 9
9 6 5 4 3 2 1 8 7 0
9+7+7+7+7+7+7+15+15+9


0 1 2 3
0 

 0  1  2  3  4  5  6  7  8  9 10
 0  2  1  4  3 10  9  8  7  6  5

formar pares com o menor desperdício de bits


*/

#define ll long long


void solve() {
    int l, r;
    cin >> l >> r;

    vector<int> ans(r+1, -1);
    for (int i=r; i>=0; i--) {
        if (ans[i] >= 0) continue;
        int choice = ((1 << (32 - __builtin_clz(i))) - 1) ^ i;
        ans[choice] = i;
        ans[i] = choice;
    }

    ll sum = 0;
    for (int i=0; i<=r; i++) {
        sum += i | ans[i];
    }
    cout << sum << '\n';
    for (int i=0; i<=r; i++) {
        cout << ans[i] << ' ';
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
