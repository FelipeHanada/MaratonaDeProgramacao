#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

int n;
constexpr int MAX_N = 1e6;
pii v[MAX_N];

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i].s >> v[i].f;
    }
    sort(v, v+n);

    int ans = 0;
    pii i = {0, 1}, j = {n-1, v[n-1].s};
    while (i < j) {
        ans = max(ans, v[i.f].f + v[j.f].f);

        i.s++;
        if (i.s > v[i.f].s) i = {i.f+1, 1};

        j.s--;
        if (j.s <= 0) j = {j.f-1, v[j.f-1].s};
    }

    cout << ans << '\n';
}