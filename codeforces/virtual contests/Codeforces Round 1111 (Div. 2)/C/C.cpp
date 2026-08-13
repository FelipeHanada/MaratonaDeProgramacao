#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        
        bool good = 1;
        for (int i=0; good && i<n; i++) good = a[i] == b[i];
        if (good) {
            cout << "0\n";
            continue;
        }

        good = 0;
        for (int i=0; !good && i<n; i++) good = !b[i];
        if (!good) {
            cout << "-1\n";
            continue;
        }

        good = 0;
        for (int i=0; !good && i<n; i++) good = a[i];
        if (!good) {
            cout << "-1\n";
            continue;
        }

        int flip_0 = 0, flip_1 = 0;
        for (int i=0; i<n; i++) {
            if (a[i] != b[i]) {
                if (a[i]) flip_1++;
                else flip_0++;
            }
        }

        if (flip_1 & 1) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}

/*
1 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1

*/