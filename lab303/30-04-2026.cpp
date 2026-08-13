#include <bits/stdc++.h>
using namespace std;

constexpr int N = int(1e6);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cnt(N, 0);
    int big = INT32_MIN;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        big = max(big, x);
    }

    int ans = -1;
    for (int i=big; ans == -1; i--) {
        int g = 0;
        for (int j=i; j<=big; j+=i) {
            g += cnt[j];
        }

        if (g > 1) ans = i;
    }

    cout << ans << '\n';
}
