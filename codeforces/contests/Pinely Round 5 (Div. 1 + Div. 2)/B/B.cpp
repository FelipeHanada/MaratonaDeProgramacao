#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second

/*
5
#.#.#
.#.#.
#.#.#
.#.#.
#.#.#

..##.
.#.#.
.##..
..##.

...1#
...#2.
.....#

.#X#.
##X##
.X.X.
.....
*/

void solve() {
    int n;
    cin >> n;
    char grid[n][n];
    pii any = {-1, -1};
    int blacks = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                any = {i, j};
                blacks++;
            }
        }
    }
    if (blacks == 0) {
        cout << "YES\n";
        return;
    }

    if (blacks == 4 && (any.f > 0 && any.s > 0) && grid[any.f-1][any.s-1] == '#' && grid[any.f-1][any.s] == '#' && grid[any.f][any.s-1] == '#') {
        cout << "YES\n";
        return;
    }

    // if it is doable, we can make it by drawing a diagonal
    bool ok;
    int count;
    pii curr;
    int step;
    
    ok = true;
    count = -1;
    for (curr = any, step = 0; ok && curr.f >= 0 && curr.s >= 0; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f--;
        else curr.s--;
    }
    for (curr = any, step = 1; ok && curr.f<n && curr.s<n; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f++;
        else curr.s++;
    }
    if (ok && count == blacks) {
        cout << "YES\n";
        return;
    }

    ok = true;
    count = -1;
    for (curr = any, step = 1; ok && curr.f >= 0 && curr.s >= 0; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f--;
        else curr.s--;
    }
    for (curr = any, step = 0; ok && curr.f<n && curr.s<n; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f++;
        else curr.s++;
    }
    if (ok && count == blacks) {
        cout << "YES\n";
        return;
    }

    ok = true;
    count = -1;
    for (curr = any, step = 0; ok && curr.f >= 0 && curr.s < n; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f--;
        else curr.s++;
    }
    for (curr = any, step = 1; ok && curr.f<n && curr.s>=0; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f++;
        else curr.s--;
    }
    if (ok && count == blacks) {
        cout << "YES\n";
        return;
    }

    ok = true;
    count = -1;
    for (curr = any, step = 1; ok && curr.f >= 0 && curr.s < n; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f--;
        else curr.s++;
    }
    for (curr = any, step = 0; ok && curr.f<n && curr.s>=0; step++) {
        if (grid[curr.f][curr.s] == '#') count++;
        if (step % 2) curr.f++;
        else curr.s--;
    }
    if (ok && count == blacks) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
