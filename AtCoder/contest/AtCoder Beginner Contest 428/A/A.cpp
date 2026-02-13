#include <bits/stdc++.h>
using namespace std;



int main() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;

    int t = x;
    int ans = 0;
    while (t) {
        int run_time = min(a, t);
        ans += s * run_time;
        t -= run_time;
        t -= min(b, t);
    }
    cout << ans << '\n';
}