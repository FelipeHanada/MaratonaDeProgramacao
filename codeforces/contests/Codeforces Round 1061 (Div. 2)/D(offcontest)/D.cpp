#include <bits/stdc++.h>
using namespace std;


int query(int i, int x) {
    cout << "? " << i << ' ' << x << '\n';
    fflush(stdout);
    cin >> i;
    return i;
}

void solve() {
    int n;
    cin >> n;

    set<int> s;
    for (int i=1; i<n; i++) s.insert(i);

    int expected = (n+1)/2;
    int target = 0;
    
    for (int d = 0; !s.empty(); d++) {
        set<int> z, o;

        int cnt = 0;
        for (int i : s) {
            if (query(i, (1<<d))) {
                o.insert(i);
                cnt++;
            } else {
                z.insert(i);
            }
        }

        if (cnt < expected) {
            target |= (1<<d);
            swap(s, o);
        } else {
            swap(s, z);
            if (s.empty() && (target|(1<<(d+1))) <= n) target |= (1<<(d+1));
        }

        expected = (s.size() + 1 + (!target))/2;
        // se target ainda é 0, então precisamos desconsiderar o 0 somando 1
    }

    cout << "! " << target << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
