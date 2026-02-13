#include <bits/stdc++.h>
using namespace std;


constexpr int K = 25;
constexpr int MAX_N = 1e5;
int n, q;

int stmin[K+1][MAX_N];
int stmax[K+1][MAX_N];

int log2_floor(unsigned long long i) {
    return __builtin_clzll(1) - __builtin_clzll(i);
}

int rminq(int l, int r) {
    int k = min(K, log2_floor(r-l+1));
    int ans = stmin[k][l];
    while (l+(1<<k)-1 <= r) {
        ans = min(ans, stmin[k][l]);
        l += (1<<k);
    }
    return min(ans, stmin[k][r-(1<<k)+1]);
}

int rmaxq(int l, int r) {
    int k = min(K, log2_floor(r-l+1));
    int ans = stmax[k][l];
    while (l+(1<<k)-1 <= r) {
        ans = max(ans, stmax[k][l]);
        l += (1<<k);
    }
    return max(ans, stmax[k][r-(1<<k)+1]);
}

int main() {
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> stmin[0][i];
        stmax[0][i] = stmin[0][i];
    }

    //precomputation
    for (int j=1; j<=K; j++) {
        for (int i=0; i+(1<<j)-1<n; i++) {
            stmin[j][i] = min(stmin[j-1][i], stmin[j-1][i+(1<<(j-1))]);
            stmax[j][i] = max(stmax[j-1][i], stmax[j-1][i+(1<<(j-1))]);
        }
    }

    cin >> q;
    int a, b;
    while (q--) {
        cin >> a >> b;
        int first = rminq(a, b);
        int last = rmaxq(a, b);
        int max_left = (a>0) ? rmaxq(0, a-1) : 0;
        int max_right = (b<n-1) ? rmaxq(b+1, n-1) : 0;

        cout << setprecision(1) << fixed
            << first + max((last - first) / (double)2, (double)max(max_left, max_right)) << '\n';
    }
}
