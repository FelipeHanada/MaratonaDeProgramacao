#include <bits/stdc++.h>
using namespace std;

int n, k, b;
constexpr int MAX_N = 1e5;
int prefix[MAX_N+1];

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    cin >> n >> k >> b;
    map<int, int> broken;
    int x;
    for (int i=0; i<b; i++) {
        cin >> x;
        broken[x]++;
    }

    int ans = INT32_MAX;
    prefix[0];
    for (int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + broken[i+1];

        if (i+1-k >= 0)
            ans = min(ans, prefix[i+1] - prefix[i+1-k]);
    }

    cout << ans << '\n';
}