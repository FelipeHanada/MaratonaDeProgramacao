#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MAX_N = 1e5;
int n;
int a[MAX_N+1];
int v[MAX_N+1];
bool seen[MAX_N+1];
ll ans;

int succ(int x) { return a[x]; }

void floyd(int i) {
    int t = succ(i), h = succ(t);
    while (t != h) {
        if (seen[t]) {
            while (i != t) {
                ans += v[i]; seen[i] = true;
                i = succ(i);
            }
            return;
        }
        t = succ(t);
        h = succ(succ(h));
    }

    t = i;
    while (t != h) {
        t = succ(t);
        h = succ(h);
    }

    while (i != t) {
        ans += v[i]; seen[i] = true;
        i = succ(i);
    }

    int best = v[t];
    ans += v[t]; seen[t] = true;
    t = succ(t);
    while (t != h) {
        best = min(best, v[t]);
        ans += v[t]; seen[t] = true;
        t = succ(t);
    }
    ans -= best;
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> v[i];
    }

    ans = 0;
    fill_n(seen, n+1, false);
    for (int i=1; i<=n; i++) {
        if (seen[i]) continue;
        floyd(i);
    }

    cout << ans << '\n';
}
