#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);
constexpr int md = int(1e9)+7;
inline int add(int a, int b) { return ((a%md) + (b%md)) % md;}
inline int sub(int a, int b) { return ((a%md) - (b%md) + md) % md;}
inline int mult(int a, int b) { return ((ll)(a%md) * (b%md)) % md;}
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
inline int inv(int a) { return binpow(a, md-2); }


int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());

    auto check = [&](int x) -> bool {
        int curr = 1;
        int last = a[0].first;

        for (int i=1; i<n; i++) {
            if (a[i].second - last >= x) {
                curr++;
                last = a[i].first;
            }
        }

        return curr >= k;
    };

    int l = 0, r = int(1e9)+5;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (!l) cout << "-1\n";
    else cout << l << '\n';
}
