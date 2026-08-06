#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> k >> m;

        if (k > m) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i=0; i<k-1; i++) {
                cout << m/k << ' ';
            }
            cout << m - m/k*(k-1) << ' ';
            for (int i=k; i<n; i++) cout << "1 ";
            cout << '\n';
        }
    }
}
/*
x x x x x x
(1..    k) deve ser divisível por m
podemos faze


6 4 3
x x x x | y y

 1 4 3 1 = 9

a1 + a2 + a3 + a4 = 3p      s.t. ai > 0


*/