#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = min(
        min(abs(a+b-c-d), abs(a+c-b-d)),
        abs(a+d-b-c)
    );
    cout << ans << '\n';
}