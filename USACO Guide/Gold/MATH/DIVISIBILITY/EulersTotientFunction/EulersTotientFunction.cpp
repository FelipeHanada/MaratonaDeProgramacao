#include <bits/stdc++.h>
using namespace std;


int phi(int n) {
    int x = n;

    for (int i=2; i*i<=n; i++) {
        if (n % i != 0) continue;

        while (n % i == 0)
            n /= i;

        x -= x / i;
    }

    if (n > 1) {
        x -= x / n;
    }

    return x;
}

int main() {
    for (int i=1; i<=10; i++) {
        cout << "phi(" << i << ") = " << phi(i) << endl;
    }
}
