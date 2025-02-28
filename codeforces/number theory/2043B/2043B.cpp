#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, d;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n >> d;
        cout << "1 ";

        // if d * n! is divisible by 3 (eq. d = 3 or n >= 3)
        if (d % 3 == 0 || n >= 3)
            cout << "3 ";
        
        if (d == 0 || d == 5)
            cout << "5 ";

        // since 7 is prime, we can consider n! with d = 5
        // because we can divide the ddd...ddd by d (and if it is divisible by)
        // ...5555555
        // ...555545
        // ...55544
        // ...5546
        // ...542
        // ...50
        // ...5
        // since none of the 5, 55, 555, 5555, 55555 are divisible by 7
        // then if and only if n! is divisible by 6 = 3!
        if (d == 7 || n >= 3)
            cout << "7 ";

        // if d * n! is divisible by 9
        // 6! = 720 = 9 * 80
        if (d == 9 || n >= 6 || (d % 3 == 0 && n >= 3))
            cout << "9 ";

        cout << "\n";
    }
}