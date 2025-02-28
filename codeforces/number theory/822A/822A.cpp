#include <bits/stdc++.h>
using namespace std;


int fac[13];
int main() {
    fac[0] = 1;
    for (int i=1; i<13; i++)
        fac[i] = fac[i-1] * i;

    int a, b;
    cin >> a >> b;
    cout << fac[min(a, b)] << "\n";
}