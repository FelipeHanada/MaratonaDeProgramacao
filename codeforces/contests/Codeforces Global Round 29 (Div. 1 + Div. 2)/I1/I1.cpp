#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
1 1 2 -1 3 -2 4

X   X X   X X   X  X     X   X
0 0 1 3 0 4 9 3 10 18 9  19  30 18
 0 1 2 3 4 5 6 7  8  9 10  11  12

*/

int main() {
    int n, m;
    cin >> n >> m;

    ll curr = 0;
    ll d = 0;
    for (int i=0; i<n; i++) {
        cout << curr << ' ';
        curr += d * (i % 2 ? -1 : 1);
        d++;
    }
    cout << '\n';
}
