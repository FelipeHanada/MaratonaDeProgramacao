#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;

int n;
vector<string> a;

void solve(int l, int r, int x) {
    if (r - l <= 1) return;

    int last = INT32_MAX;
    int i;
    for (i=r-1; i>=l; i--) {
        if (x >= a[i].size()) {
            last = INT32_MIN;
        } else {
            if (a[i][x] > last) break;
            last = a[i][x];
        }
    } i++;

    for (int j=l; j<i; j++) {
        a[j] = string(a[j].begin(), a[j].begin() + x);
    }

    while (i < r) {
        int j = i;

        while (j < r && a[i][x] == a[j][x]) j++;
        solve(i, j, x+1);

        i = j;
    }
}


int main() { _
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];

    solve(0, n, 1);

    for (int i=0; i<n; i++) cout << a[i] << '\n';
}
