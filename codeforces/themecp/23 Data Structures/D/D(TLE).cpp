#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int flog2(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
}

constexpr int MAX_N = int(2e5)+1;
int a[MAX_N];
ll prefix[MAX_N+1];

constexpr int K = 18;
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

        map<int, vector<int>> m;
        for (int i=0; i<n; i++) {
            m[a[i]].push_back(i);
        }

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

        set<int> bar;
        bar.insert(-1); bar.insert(n+1);

        bool ok = 1;
        for (auto it = m.rbegin(); it != m.rend() && ok; it++) {
            auto [maxi, vec] = *it;
            for (int i : vec) {
                int l = *(--lower_bound(bar.begin(), bar.end(), i+1)) + 1;
                int r = *upper_bound(bar.begin(), bar.end(), i+1);
    
                if (i+1 == l) continue;
                ll big = querymax(i+1, r), small = querymin(l, i+1);
                ok = ok && (big - small <= a[i]);
            }
    
            for (int i : vec) bar.insert(i+1);
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
