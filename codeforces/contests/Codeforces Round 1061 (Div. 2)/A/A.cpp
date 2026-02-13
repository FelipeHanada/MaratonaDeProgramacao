#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // 8 3 ->  2 2 4
        // 7 3 -> 2 2 3
        // 6 2 -> 2 2 2
        // 5 2 -> 1 1 3
        // 4 1 ->  1 1 2 | 0 1 3
        // 3 1 ->  1 1 1
        // 2 0 ->  0 2
        cout << (n-1)/2 << '\n';
    }
}