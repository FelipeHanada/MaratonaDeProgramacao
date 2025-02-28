#include <bits/stdc++.h>
using namespace std;


void move(int a, int b) {
    cout << a << " " << b << "\n";
}

void hanoi(int a, int b, int c, int n) {
    // move disks from a to c using b
    if (n == 1) {
        move(a, c);
        return;
    }

    hanoi(a, c, b, n - 1);
    move(a, c);
    hanoi(b, a, c, n - 1);
}

/*
f(0) = 0
f(1) = 1
f(n) = 2 * f(n - 1) + 1 = 2 * (2 * f(n - 2) + 1) + 1 = 2^k * f(n - k) + [2^0 + 2^1 + ... + 2^(k-1)]

a1(qn−1) / (q−1)

let n - k = 1
    k = n - 1

f(n) = 2^k * f(n - k) + [2^0 + 2^1 + ... + 2^(k-1)] =
     = 2^(n-1) * f(1) + [2^0 + 2^1 + ... + 2^(n-2)] =
     = 2^(n-1) + 1*(2^(n-1)-1) / (2-1) =
     = 2^(n-1) + (2^(n-1)-1) =
     = 2^n + -1
*/

int hanoi_moves(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return (1 << n) - 1;
}

int main() {
    int n;
    cin >> n;

    cout << hanoi_moves(n) << "\n";
    hanoi(1, 2, 3, n);
}
