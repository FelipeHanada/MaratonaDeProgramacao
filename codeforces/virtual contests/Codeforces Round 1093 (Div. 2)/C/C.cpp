#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int p, q;
        cin >> p >> q;

        pair<int, int> ans = { -1, -1 };
        for (int n=1; n+2*n*n+n <= p+q*2; n++) {
            if ((p + 2*q - n) % (2*n+1)) continue;
            int m = (p + 2*q - n) / (2*n+1);

            if (p >= m - n) {
                ans = { n, m };
                break;
            }
        }

        if (ans.first == -1) {
            cout << "-1\n";
        } else {
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
}

/*
1x1 => 4
1x2 => 7
1x3 => 10



nxm => n(m+1) + m(n+1) palitinhos
        = n + 2nm + m

temos p + 2*q palitinhos

se fixarmos n: 
    n + 2nm + m = p + 2*q
    m(2n + 1) + n = p + 2*q
    m(2n + 1) = p + 2*q - n
    m = (p + 2*q - n) / (2n + 1)


1 + 2*1*2 + 2 = 1 + 4 + 2 = 7
1 + 2*1*3 + 3 = 

*/
