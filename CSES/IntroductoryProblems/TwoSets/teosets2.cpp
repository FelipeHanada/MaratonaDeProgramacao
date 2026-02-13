#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    int curr = 1;
    deque<int> b;
    if (n % 4 == 3) {
        cout << 2 + ((n - 3) / 2) << '\n';
        cout << "1 2 ";
        b.push_back(3);
        curr = 4;
    } else {
        cout << n / 2 << '\n';
    }

    for (int i=curr; i<=n; i+=4) {
        cout << i << ' ' << i + 3 << ' ';
        b.push_back(i+1);
        b.push_back(i+2);
    }
    cout << '\n';

    cout << b.size() << '\n';
    for (int x : b) {
        cout << x << ' ';
    }
    cout << '\n';
}
