#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto check = [&](int t) -> bool {
        int i = 1;
        int rem = m, curr = 1, first = a[0];
        while (i < a.size()) {
            if (a[i] - first > t || curr == c) {
                rem--;
                curr = 0;
                first = a[i];
            }

            curr++;
            i++;
        }

        if (rem <= 0) return false;

        return true;
    };

    int l = 0, r = a.back();
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