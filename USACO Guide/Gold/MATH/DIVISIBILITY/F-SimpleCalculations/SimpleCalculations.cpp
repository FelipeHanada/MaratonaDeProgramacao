#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int a = (1 << (n % k)) % k;
    cout << ((1 << a) % k + 1) % k << endl;
}
