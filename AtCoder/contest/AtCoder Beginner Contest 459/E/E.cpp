#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

constexpr int md = 998244353;
int mult(int a, int b) {
    return ((ll)a * b) % md;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int add(int a, int b) {
    a += b;
    if (a >= md) a-= md;
    return a;
}
constexpr int N = int(1e6+100);
vector<int> fat(N), finv(N);
int comb(ll n, int k) {
    int ans = 1;
    for (int i=0; i<k; i++) {
        ans = mult(ans, sub(n, i));
    }
    return mult(ans, finv[k]);
}
int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mult(ans, a);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}
int inv(int a) {
    return binpow(a, md-2);
}

int main() { _
    fat[0] = 1;
    for (int i=1; i<N; i++) {
        fat[i] = mult(fat[i-1], i);
    }
    finv[N-1] = inv(fat[N-1]);
    for (int i=N-2; i>=0; i--) {
        finv[i] = mult(finv[i+1], i+1);
    }

    int n;
    cin >> n;
    vector<ll> p(n), c(n), d(n);
    p[0] = -1;
    for (int i=1; i<n; i++) {
        cin >> p[i]; p[i]--;
    }
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n; i++) cin >> d[i];

    vector<int> out_deg(n, 0);
    for (int i=1; i<n; i++) out_deg[p[i]]++;
    queue<int> q;
    for (int i=0; i<n; i++) if (!out_deg[i]) q.push(i);


    vector<int> ans(n, 1);
    vector<ll> choose_from(n, 0);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        choose_from[curr] = add(choose_from[curr], c[curr]);
        ans[curr] = mult(ans[curr], comb(choose_from[curr], d[curr]));

        if (p[curr] == -1) continue;
        ans[p[curr]] = mult(ans[p[curr]], ans[curr]);
        choose_from[p[curr]] = add(choose_from[p[curr]], sub(choose_from[curr], d[curr]));
        if (!(--out_deg[p[curr]])) {
            q.push(p[curr]);
        }
    }

    cout << ans[0] << '\n';
}

