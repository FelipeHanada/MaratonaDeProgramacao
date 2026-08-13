#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % 4) cout << "NO\n";
        else cout << "YES\n";
    }
}


/*
4
x x x x

1 -1 -1 1

1 1 1 1 -1 -1

só dá pra aumentar 2 ou diminuir 2

2   -> -2 (-4)
1 1 => -1 -1 

(+4)

*/