#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i=0; i<n; i++) b[i] = a.back() - a[n-i-1];

    auto checkleft = [&](vector<int>& v, int R, int i) {
        int curr = i, r = R - 2;
        while (curr && r) {
            auto lb = lower_bound(v.begin(), v.end(), v[curr]-r/2);
            int newcurr = distance(v.begin(), lb);
            if (newcurr == curr) break;
            curr = newcurr;
            r-=2;
        }

        return curr == 0;
    };

    auto checkright = [&](vector<int>& v, int R, int i) {
        int curr = distance(v.begin(), upper_bound(v.begin(), v.end(), v[i]+R))-1,
            r = R - 2;
        
        while (curr < n - 1 && r) {
            auto ub = upper_bound(v.begin(), v.end(), v[curr] + r/2);
            int newcurr = distance(v.begin(), ub) - 1;
            if (newcurr == curr) break;
            curr = newcurr;
            r-=2;
        }

        return curr == n - 1;
    };

    auto check = [&](int R) -> bool {
        int l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (checkleft(a, R, mid)) l = mid;
            else r = mid;
        }
        if (checkright(a, R, l)) return 1;

        l = 0, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (checkleft(b, R, mid)) l = mid;
            else r = mid;
        }
        if (checkright(b, R, l)) return 1;

        return 0;
    };


    int l = 0, r = 2*(a.back()-a.front());
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << r/2 << '.' << ((r%2) * 5) << '\n';
}
