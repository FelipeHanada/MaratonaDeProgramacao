#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    /* ans = maximum integer value of x that satisfies
    n * x + n - 1 <= k
    n * x <= k - n + 1
    x <= (k - n + 1) / n = (k+1)/n - 1
    */

    cout << (k + 1) / n - 1 << '\n';
}