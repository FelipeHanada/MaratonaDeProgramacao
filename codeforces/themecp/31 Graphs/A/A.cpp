#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int n;
vector<int> a;

int solve(int i, int j, int delta=0) {
    int first = a[i] - delta;
    if (first <= 0 || first > j - i) return -1;
    if (j - i <= 1) return 0;

    int mid = (i + j) / 2;
    int x, y;
    if (first <= (j - i) / 2) {
        x = solve(i, mid, delta);
        y =  solve(mid, j, delta + (j - i) / 2);
    } else {
        x = solve(i, mid, delta + (j - i) / 2);
        y = solve(mid, j, delta);
    }
    int ans = (first > (j - i) / 2) + x + y;

    if (x == -1 || y == -1) return -1;
    return ans;
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        a.resize(n);
        for (int i=0; i<n; i++) cin >> a[i];

        cout << solve(0, n) << '\n';
    }
}
