#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 2e5;
int n;
int x;

int d[MAX_N+1];

int main() {
    cin >> n;

    fill_n(d, n+1, INT32_MAX);
    for (int i=0; i<n; i++) {
        cin >> x;
        int l = lower_bound(d, d+n, x) - d;
        d[l] = x;
    }

    int len = lower_bound(d, d+n+1, INT32_MAX) - d;
    cout << len << '\n';
}
