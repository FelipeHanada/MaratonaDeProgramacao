#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100000;
int n;
int a[MAX_N+1];
bool seen[MAX_N+1];

int succ(int x) {
    return a[x];
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    fill_n(seen, n+1, false);
    for (int i=1; i<=n; i++) {
        if (seen[i]) continue;
        int t = i, h = succ(t);
        while (t != h) {
            t = succ(t);
            if (seen[t]) break;
            h = succ(succ(h));
        }
        if (seen[t]) continue;

        seen[i] = true;
        t = succ(t);
        seen[t] = true; ans++;
        while (t != h) {
            t = succ(t);
            seen[t] = true; ans++;
        }
    }

    cout << ans << '\n';
}
