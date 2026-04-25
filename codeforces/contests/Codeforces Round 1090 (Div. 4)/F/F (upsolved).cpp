#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        
        if ((x+y)%2 && !y) {
            cout << "NO\n";
            continue;
        }
        if (!((x+y)%2) && !x) {
            cout << "NO\n";
            continue;
        }
        if (x > y) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        int root = 1;
        int aux = 2;
        if (!((x+y)%2)) {
            cout << "1 2\n";
            root = 2; aux = 3;
            x--;
        }
        y--;

        while (x) {
            cout << root << ' ' << aux << '\n';
            cout << aux << ' ' << aux+1 << '\n';
            aux += 2;
            x--; y--;
        }

        while (y) {
            cout << root << ' ' << aux << '\n';
            aux++;
            y--;
        }
    }
}