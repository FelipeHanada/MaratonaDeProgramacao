#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    vector<ll> prefix(n), suffix(n);
    prefix[0] = x[0];
    for (int i=1; i<n; i++) prefix[i] = prefix[i-1] + x[i];
    suffix.back() = x.back();
    for (int i=n-2; i>=0; i--) suffix[i] = suffix[i+1] + x[i];
    suffix.push_back(0);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        auto eval = [&](ll y) -> ll {
            ll ans = 0;
            auto ub = upper_bound(x.begin(), x.end(), y);
            int i = distance(x.begin(), ub);
            if (i) ans += (y*i - prefix[i-1]) * a;
            if (i < n) ans += (suffix[i] - y * (n-i)) * b;
            return ans;
        };

        int l = -1, r = int(1e6) + 5;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (eval(mid) > eval(mid + 1)) l = mid;
            else r = mid;
        }

        cout << eval(r) << '\n';
    }
}

/*
let f(y) be the cost of delivering to point y

    f(y) = a * (y - x)[forall x <= y]
         + b * (x - y)[forall x > y]

let i < j < k, if f(j) > f(k)

f(i) = a * (i - x)[forall x <= i]
     + b * (x - i)[forall x > i]

a * (j - x)[x <= j] + b * (x - j)[x > j] > a * (k - x)[x <= k] + b * (x - k)[x > k]
since j < k, if x <= j, then x <= k
    let X be the sum of x's s.t. x > j and x <= k

b * (x - j)[x > j] > a * (k - x)[j < x <= k] + b * (x - k)[x > k]

*/
