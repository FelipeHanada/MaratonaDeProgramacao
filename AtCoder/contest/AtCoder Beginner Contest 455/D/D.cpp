#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    int n, q;
    cin >> n >> q;

    vector<int> next(2*n, -1);
    vector<int> prev(2*n, -1);
    iota(next.begin(), next.begin() + n, n);
    iota(prev.begin() + n, prev.end(), 0);

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        x+=n; y+=n;

        next[prev[x]] = -1;
        prev[x] = y;
        next[y] = x;
    }

    for (int i=0; i<n; i++) {
        int size = 0;
        int curr = i;
        while (next[curr] != -1) {
            size++;
            curr = next[curr];
        }

        cout << size << ' ';
    }
    cout << '\n';
}