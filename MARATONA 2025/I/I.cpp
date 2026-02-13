#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> d(n-1);
    vector<int> r(n-1);
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    r[0] = 1;
    for (int i=0; i<n-1; i++) {
        cin >> x2 >> y2;
        d[i] = abs(x2 - x1) + abs(y2 - y1);
        if (i>0) r[i] = d[i-1] - r[i-1];
        tie(x1, y1) = make_tuple(x2, y2);
    }

    int low = 0, high = INT32_MAX;
    for (int i=0; i<n-1; i++) {
        if (i % 2) {
            // 1 <= r[i] - k <= d[i] - 1
            // k >= r[i] - d[i] + 1 AND k <= r[i] - 1
            low = max(low, r[i] - d[i] + 1);
            high = min(high, r[i] - 1);
        } else {
            // 1 <= r[i] + k <= d[i] - 1
            // k >= 1 - r[i] AND k <= d[i] - r[i] - 1
            low = max(low, 1 - r[i]);
            high = min(high, d[i] - r[i] - 1);
        }
    }

    if (low > high) {
        cout << -1 << '\n';
    } else {
        cout << high + 1 << '\n';
    }
}
