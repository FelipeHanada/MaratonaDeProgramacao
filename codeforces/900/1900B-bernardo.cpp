#include <bits/stdc++.h>
using namespace std;


int solve(int a, int b, int c) {
    return (b + c) % 2 == 0 ? 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, c;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> a >> b >> c;

        cout << solve(a, b, c) << " "
             << solve(b, a, c) << " "
             << solve(c, a, b) << endl;
    }
}
