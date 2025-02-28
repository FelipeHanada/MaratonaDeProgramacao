#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;

        int mod1 = 0, mod2 = 0;
        for (int j=0; j<n; j++) {
            int x;
            cin >> x;
            if (x % 3 == 1) mod1++;
            else if (x % 3 == 2) mod2++;
        }

        int d;
        if (mod1 > mod2) {
            d = (mod1 - mod2) % 3;
        } else {
            d = (mod2 - mod1)*2 % 3;
        }

        // if d == 0, ans = 0
        // if d == 1, you may remove a mod1 element or increase 2 times
        // if d == 2, ans = 1 (you can either remove a mod2 element or increase 1 time)

        switch (d) {
            case 0:
                cout << 0 << "\n";
                break;
            case 1:
                if (mod1) {
                    cout << 1 << "\n";
                } else {
                    cout << 2 << "\n";
                }
                break;
            case 2:
                cout << 1 << "\n";
        }
    }
}