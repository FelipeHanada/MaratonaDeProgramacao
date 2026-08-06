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


int main() { _
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) cin >> a[i].second >> a[i].first;
    sort(a.rbegin(), a.rend());

    int q; cin >> q;
    vector<pair<int, int>> b(q);
    for (int i=0; i<q; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.rbegin(), b.rend());

    int curr = 0;
    vector<int> ans(q);
    int i = 0;
    for (int j=0; j<q; j++) {
        while (i < n && a[i].first > b[j].first) {
            curr = max(curr, a[i].second);
            i++;
        }

        ans[b[j].second] = curr;
    }

    for (int i=0; i<q; i++) {
        cout << ans[i] << '\n';
    }
}
