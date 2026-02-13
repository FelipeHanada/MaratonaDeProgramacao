#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int big = max(a, max(b, c));
    int small = min(a, min(b, c));
    if (big - small >= 10) {
        cout << "check again" << '\n';
    } else {
        cout << "final " << a + b + c - big - small << '\n';
    }
}
