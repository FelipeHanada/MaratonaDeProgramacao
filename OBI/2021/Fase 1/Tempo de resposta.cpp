#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    map<int, int> ans;
    map<int, int> receive;
    int t = 0;
    for (int i=0; i<n; i++) {
        char op; int x;
        cin >> op >> x;
        if (op == 'R') {
            receive[x] = t;
            t++;
        } else if (op == 'E') {
            ans[x] += t - receive[x];
            receive[x] = -1;
            t++;
        } else {
            t += x - 1;
        }
    }

    for (auto [ x, y ] : ans) {
        cout << x << ' ' << (receive[x] == -1 ? y : -1) << '\n';
    }
}