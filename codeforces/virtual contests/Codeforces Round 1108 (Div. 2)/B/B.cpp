#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;

        if (n == 1) {
            cout << "1\n";
        } else if (n == 2) {
            cout << "-1\n";
        } else {
            vector<ll> ans = { 1, 2, 3 };
            ll sum = accumulate(ans.begin(), ans.end(), 0);
            while (ans.size() < n) {
                ans.push_back(sum);
                sum *= 2;
            }

            for (ll x : ans) cout << x << ' ';
            cout << '\n';
        }
    }
}

/*
1 = 1

x + y é divisível por x e por y
wlog x < y, y deve ser múltiplo de x e x deve ser 0

x + y + z é divisível por x, y e z
wlog x < y < z

1. y + z é múltiplo de x
2. x + z é múltiplo de y
3. x + y é múltiplo de z

vamos tomar z = x + y, isso resolve (3)
substituindo temos
(1) <-> x + 2y é múltiplo de x
(2) <-> 2x + y é múltiplo de y

1 2 3



1 2 6 9 18


*/
