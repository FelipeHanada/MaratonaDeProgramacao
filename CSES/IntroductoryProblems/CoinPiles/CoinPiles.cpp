#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, a, b;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> a >> b;

        if (b > a)
            swap(a, b);

        if (b == 0) {
            if (a == 0)
                cout << "YES";
            else
                cout << "NO";

        } else if (a <= 2*b && a % 3 == (2*b) % 3)
            cout << "YES";
        else {
            cout << "NO";
        }

        cout << "\n";
    }
}
