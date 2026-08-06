#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, d; cin >> n >> d;
    string s; cin >> s;

    int l = 0, r = 0, cnt = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        while (l < i-d) cnt -= int(s[l++] == 'G');
        while (r < n && r <= i+d) cnt += int(s[r++] == 'G');
        ans += int(cnt == 0);
    }
    cout << ans << '\n';
}
