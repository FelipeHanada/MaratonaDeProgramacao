#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    int x = 0;
    for (int i=0; i<n; i++) {
        char c;
        cin >> c;
        cin >> c;

        if (c == '+') {
            x++;
        } else {
            x--;
        }

        cin >> c;
    }

    cout << x << '\n';
}