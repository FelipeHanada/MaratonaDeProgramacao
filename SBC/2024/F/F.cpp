#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int fib[n + 2];
    fib[0] = 0; fib[1] = 1;

    for (int i=2; i<=n + 1; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout << fib[n + 1] << "\n";
}
