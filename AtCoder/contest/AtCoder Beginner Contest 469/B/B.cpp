#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int n; string s;
    cin >> n >> s;

    int ans = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'o') continue;
        if (i > 0 && s[i-1] == 'o') continue;
        if (i < n-1 && s[i+1] == 'o') continue;
        ans++;
    }

    cout << ans << '\n';
}
