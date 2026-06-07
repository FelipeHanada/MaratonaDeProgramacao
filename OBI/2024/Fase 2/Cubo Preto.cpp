#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int ans0, ans1, ans2, ans3;

    ans3 = 8;
    ans2 = 12 * (n  - 2);
    ans1 = 6 * (n - 2) * ( n - 2);
    ans0 = n * n * n - ans1 - ans2 - ans3;
    cout << ans0 << '\n';
    cout << ans1 << '\n';
    cout << ans2 << '\n';
    cout << ans3 << '\n';
}
