#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;

    cin >> n;


    while (n >= 10) {
        cout << n << "\n";

        n = n / 10 * 3 + n % 10;
    }

    cout << n << "\n";
}