#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i=0; i<n; i++) cout << 1 + (i ^ 1) << ' ';
        cout << '\n';
    }
}
