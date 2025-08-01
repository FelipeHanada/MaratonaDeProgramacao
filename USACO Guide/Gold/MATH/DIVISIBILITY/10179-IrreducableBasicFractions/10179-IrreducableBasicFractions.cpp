//  https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1120
#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1e9;

int phi(int n) {
    int result = n;

    for (int i=2; i*i<=n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;

            result -= result / i;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << phi(n) << endl;
    }
}