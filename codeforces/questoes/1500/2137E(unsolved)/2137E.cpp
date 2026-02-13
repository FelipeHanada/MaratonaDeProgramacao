#include <bits/stdc++.h>
using namespace std;

/*
5
3 3
0 2 1 -> 0 2 1 -> 0 2 1 -> 0 2 1

2 4
0 2

4 1
0 0 1 1 -> 2 2 2 2

8 7
6 6 2 4 3 0 1 8
-> 5 5 2 4 3 0 1 5
-> 6 6 2 4 3 0 1 6
-> 5 5 2 4 3 0 1 5
-> 6 6 2 4 3 0 1 6
-> 5 5 2 4 3 0 1 5
-> 6 6 2 4 3 0 1 6
-> 5 5 2 4 3 0 1 5

2 2
0 0 -> 1 1 -> 0 0
*/


void solve() {
    int n, k;
    cin >> n >> k;

    multiset<int> ms;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}