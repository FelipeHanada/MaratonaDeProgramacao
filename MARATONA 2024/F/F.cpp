#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int a = 0, b = 1;
    for (int i=0; i<n; i++) {
        tie(a, b) = make_tuple(b, a + b);
    }

    cout << b << '\n';
}
