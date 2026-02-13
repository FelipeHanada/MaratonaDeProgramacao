#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_X = 1e9;

int main() {
    int n;
    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        cout << (x % 11 <= x / 111 ? "YES" : "NO") << '\n';
    }
}
