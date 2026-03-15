#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> hay(n);
    for (int i=0; i<n; i++) {
        cin >> hay[i];
    }
    sort(hay.begin(), hay.end());

    auto check = [&](int r) -> bool {
        int used = 0;
        int i=0;
        while (i < n) {
            used++;
            int start = hay[i];
            while (i < n && hay[i] <= start + 2 * r) i++;
        }

        return used <= k;
    };

    int l = 0, r = hay.back() - hay.front();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << '\n';
}