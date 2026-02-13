#include <bits/stdc++.h>
using namespace std;


/*
1 2 -> 0
3 4

3 1 -> 1
4 2

4 3 -> 2
2 1

2 4 -> 3
1 3

*/

int main() {
    int n;
    cin >> n;

    int upleft, upright, downleft, downright;
    cin >> upleft;
    for (int i=0; i<n-1; i++) cin >> upright;
    for (int i=1; i<n-1; i++) {
        for (int j=0; j<n; j++) {
            cin >> downleft;
        }
    }
    cin >> downleft;
    for (int i=0; i<n-1; i++) cin >> downright;


    if (upleft < upright && upleft < downleft) {
        cout << "0\n";
    } else if (upright < upleft && upright < downright) {
        cout << "1\n";
    } else if (downright < downleft && downright < upright) {
        cout << "2\n";
    } else {
        cout << "3\n";
    }
}
