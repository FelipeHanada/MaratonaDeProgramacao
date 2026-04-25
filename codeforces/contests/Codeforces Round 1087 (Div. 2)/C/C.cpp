#include <bits/stdc++.h>
using namespace std;


using ll = long long;

bool query(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << '\n';
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        bool done = 0;

        for (int i=4; !done && i+1<2*n; i+=2) {
            if (query(i, i+1)) {
                cout << "! " << i+1 << '\n';
                done = 1;
            }
        }
        if (done) continue;

        if (query(0, 1)) {
            cout << "! 1\n";
        } else if (query(1, 2)) {
            cout << "! 2\n";
        } else if (query(0, 2)) {
            cout << "! 1\n";
        } else {
            cout << "! 4\n";
        }
    }
}
