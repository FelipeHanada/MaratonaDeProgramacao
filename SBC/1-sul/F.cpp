#include <bits/stdc++.h>
using namespace std;


int main() {
    double a, b;
    cin >> a >> b;

    cout << setprecision(6) << fixed << ((100 + a) * (100 + b) / 100 - 100) << '\n';
}
