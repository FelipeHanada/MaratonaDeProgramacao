#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int flog2(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
}

constexpr int MAX_N = int(2e5)+5;
int a[MAX_N];
ll prefix[MAX_N+1];

constexpr int K = 25;
ll stmin[K][MAX_N+1], stmax[K][MAX_N+1];
ll querymin(int l, int r) {
    int size = flog2(r - l);
    return min(stmin[size][l], stmin[size][r-(1<<size)]);
}
ll querymax(int l, int r) {
    int size = flog2(r - l);
    return max(stmax[size][l], stmax[size][r-(1<<size)]);
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];

        prefix[0] = 0;
        for (int i=1; i<=n; i++) prefix[i] = prefix[i-1] + a[i-1];

        for (int i=0; i<=n; i++) stmin[0][i] = stmax[0][i] = prefix[i];
        for (int i=1; i<K; i++) {
            int size = (1<<i);
            if (size > n+1) break;
            for (int j=0; j<=n+1-size; j++) {
                stmin[i][j] = min(stmin[i-1][j], stmin[i-1][j+(size>>1)]);
                stmax[i][j] = max(stmax[i-1][j], stmax[i-1][j+(size>>1)]);
            }
        }

        vector<int> left(n), right(n);
        stack<pair<int,int>> mono; mono.push({ INT32_MAX, -1 });
        for (int i=0; i<n; i++) {
            while (mono.top().first <= a[i]) mono.pop();
            left[i] = mono.top().second;
            mono.push({ a[i], i });
        }
        while (!mono.empty()) mono.pop();
        mono.push({ INT32_MAX, n });
        for (int i=n-1; i>=0; i--) {
            while (mono.top().first <= a[i]) mono.pop();
            right[i] = mono.top().second;
            mono.push({ a[i], i });
        }

        bool ok = 1;
        for (int i=0; ok && i<n; i++) {
            int l = left[i]+1, r = right[i]+1;
            ll small = querymin(l, i+1), big = querymax(i+1, r);

            ok = (big - small <= a[i]);
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
