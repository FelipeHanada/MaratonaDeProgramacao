#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    array<int,31> cnt;
    fill(cnt.begin(), cnt.end(), 0);

    int ans = 0;
    queue<int> window;
    while (window.size() < k) {
        window.push(x);
        {
            int y = x;
            for (int i=0; y; i++, y >>= 1) cnt[i] += y & 1;
        }
        x = ((ll) a * x + b) % c;
    }

    {
        int y = 0;
        for (int i=0; i<31; i++) if (cnt[i]) y += (1 << i);
        ans ^= y;
    }

    for (int i=k; i<n; i++) {
        {
            int y = window.front();
            for (int i=0; y; i++, y >>= 1) cnt[i] -= y & 1;
        }
        window.pop();
        window.push(x);
        {
            int y = x;
            for (int i=0; y; i++, y >>= 1) cnt[i] += y & 1;
        }

        {
            int y = 0;
            for (int i=0; i<31; i++) if (cnt[i]) y += (1 << i);
            ans ^= y;
        }
        x = ((ll) a * x + b) % c;
    }

    cout << ans << '\n';
}