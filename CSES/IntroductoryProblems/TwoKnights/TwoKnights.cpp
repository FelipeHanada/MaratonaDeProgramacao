#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll combn2(int n) {
    // computes combination (n, 2) = n! / (2 * (n-2)!)
    return n * (n - 1) / 2;
}

ll border(int n) {
    // number of squares of the form
    // n x k or k x n with 1 <= k <= n
    return 2 * n - 1;
}

ll ans[100001] = {0, 0, 6, 28, 96, 252};
void solve(const int n) {
    for (int k=6; k<=n; k++) {
        // ans
        //      (1) none of the knights is at the kth row/column
        //      (2) exactly one of the knights is at the kth row/column
        //      (3) both of the knights are at the kth row/column

        ll one = ans[k-1];

        // (2) there are 2*k-1 possible positions for such knight
        //      (2.1) 3 of these positions, attack 2 places
        //      (2.2) 6 of these positions, attack 3 places
        //      (2.3) all the others, attack 4 places

        ll k_1k_1 = (k-1) * (k-1);
        ll two1 = 3 * (k_1k_1 - 2);
        ll two2 = 6 * (k_1k_1 - 3);
        ll two3 = (border(k) - 9) * (k_1k_1 - 4);

        ll three = combn2(border(k));

        ans[k] = one + (two1 + two2 + two3) + three;
    }
}


int main() {
    int n;
    cin >> n;

    solve(n);
    for (int i=1; i<=n; i++) {
        cout << ans[i] << "\n";
    }
}
