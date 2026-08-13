#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    int rem = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        rem += x;
    }

    if (rem > 120) rem += 60 * 3;
    if (rem > 12*60) rem += 60 * 3;
    cout << rem << '\n';
}