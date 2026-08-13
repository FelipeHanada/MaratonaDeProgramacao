#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int a[3];
    fill_n(a, 3, 0);
    a[-1] = 1;

    cout << a[-1] << '\n';
    cout << a[0] << '\n';
    cout << a[1] << '\n';
    cout << a[2] << '\n';
}
