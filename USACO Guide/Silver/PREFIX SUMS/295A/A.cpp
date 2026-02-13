#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    vector<tuple<int, int, int>> operations(m);
    int l, r, d;
    for (int i=0; i<m; i++) {
        cin >> l >> r >> d;
        operations[i] = make_tuple(l, r, d);
    }

    vector<ll> op_count(m+1);
    int x, y;
    for (int i=0; i<k; i++) {
        cin >> x >> y;
        op_count[x-1]++;
        op_count[y]--;
    }

    vector<ll> diff(n+1, 0);
    for (int i=1; i<=m; i++) {
        op_count[i] += op_count[i-1];

        diff[get<0>(operations[i-1])-1] += get<2>(operations[i-1]) * op_count[i-1];
        diff[get<1>(operations[i-1])] -= get<2>(operations[i-1]) * op_count[i-1];
    }

    for (int i=1; i<=n; i++) {
        diff[i] += diff[i-1];
        a[i-1] += diff[i-1];
    }

    for (int i=0; i<n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
