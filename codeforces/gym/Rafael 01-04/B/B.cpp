#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, n, s;
        cin >> a >> b >> n >> s;

        s -= min(a, s/n) * n;
        cout << (b >= s ? "YES" : "NO") << '\n';
    }
}