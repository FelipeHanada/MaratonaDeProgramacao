#include <bits/stdc++.h>
using namespace std;


int main() {
    char a, b, c;
    cin >> a >> b >> c;

    int x = 0;
    if (a == 'X') x++;
    if (b == 'X') x++;
    if (c == 'X') x++;
    
    if (x != 2) {
        cout << "?\n";
        return 0;
    }

    if (b == 'O') {
        cout << "*\n";
        return 0;
    }

    cout << "Alice\n";
}