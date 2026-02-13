#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int sum = 1;
    for (int i=1; i<n; i++) {
        int dig_sum = 0;
        for (int x = sum; x; x/= 10) {
            dig_sum += x % 10;
        }
        sum += dig_sum;
    }

    cout << sum << '\n';
}
