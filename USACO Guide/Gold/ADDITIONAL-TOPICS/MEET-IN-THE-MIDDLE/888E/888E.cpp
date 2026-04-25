#include <bits/stdc++.h>
using namespace std;


inline int add(int a, int b, int md) {
    return (a + b) % md;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> left(n/2), right(n-n/2);
    for (int i=0; i<n/2; i++) cin >> left[i];
    for (int i=0; i<n-n/2; i++) cin >> right[i];

    vector<int> l;
    for (int i=0; i<(1<<(n/2)); i++) {
        int mask = i;
        int sum = 0;
        for (int j=0; mask; j++) if (mask & (1<<j)) {
            sum = add(sum, left[j], m);
            mask &= ~(1<<j);
        }
        l.push_back(sum);
    }
    sort(l.begin(), l.end());

    int ans = 0;
    for (int i=0; i<(1<<(n-n/2)); i++) {
        int mask = i;
        int sum = 0;
        for (int j=0; mask; j++) if (mask & (1<<j)) {
            sum = add(sum, right[j], m);
            mask &= ~(1<<j);
        }

        int target = m - 1 - sum;
        auto lb = lower_bound(l.begin(), l.end(), target),
            ub = upper_bound(l.begin(), l.end(), target);

        if (lb != l.end()) ans = max(ans, add(sum, *lb, m));
        if (ub != l.begin()) ans = max(ans, add(sum, *(ub-1), m));
    }

    cout << ans << '\n';
}