#include <bits/stdc++.h>
using namespace std;


/*
3
2 2 2
^

Quantas são as maneiras de 

*/

int n;
int a[(int)1e5];

int check(int i, int pre_zeros, int pre_ones, int expected_ones) {
    // return the amount of ways to arrange 
    if (i == n) {
        return (expected_ones == 0 && a[i-1] - 1 == pre_zeros) ? 1 : 0;
    }

    expected_ones -= pre_zeros;
    if (expected_ones < 0) return 0;

    // if the current position is 0, then pre_zeros + 1 and we will expect the same amount of 1s to come 
    return check(i+1, pre_zeros+1, pre_ones, expected_ones)
        + (expected_ones ? check(i+1, pre_zeros, pre_ones+1, expected_ones-1) : 0);
}

void solve() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << check(0, 0, 0, n) << '\n';

    // ans = ways to arrange with 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}