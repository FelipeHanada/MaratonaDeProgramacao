#include <bits/stdc++.h>
using namespace std;


void line(int i, int n, bool flipped) {
    if (n == 0) {
        cout << (flipped ? '*' : '+');
        return;
    }

    if (i < (1<<(n-1))) {
        line(i, n-1, flipped);
        line(i, n-1, flipped);
    } else {
        line(i - (1<<(n-1)), n-1, flipped);
        line(i - (1<<(n-1)), n-1, !flipped);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<(1<<n); i++) {
        line(i, n, 0);
        cout << '\n';
    }
}
