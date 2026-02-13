#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (char c : s) {
        if (c == 'i' || c== 'j') {
            ans++;
        }
    }
    cout << ans << '\n';
}
