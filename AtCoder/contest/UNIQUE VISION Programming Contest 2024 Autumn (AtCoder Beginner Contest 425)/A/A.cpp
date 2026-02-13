#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum += (i%2 ? -1 : 1) * i * i * i;
    }
    cout << sum << '\n';
}
