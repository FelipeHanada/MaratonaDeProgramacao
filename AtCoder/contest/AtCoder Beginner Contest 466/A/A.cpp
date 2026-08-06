#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int n; cin >> n;
    bool ok = 1;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x >= 0) ok = 0;
    }

    cout << (ok ? "Yes" : "No") << '\n';
}
