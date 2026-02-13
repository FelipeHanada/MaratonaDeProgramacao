#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    int curr = 0;
    cin >> curr;
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        curr = (curr << 1) | x;
    }

    int ans = 0;
    while (curr > 1) {
        if (curr & 1) {
            curr = (curr << 1) ^ curr ^ 1;
        } else {
            curr >>= 1;
        }
        ans++;
    }

    cout << ans << '\n';
}
