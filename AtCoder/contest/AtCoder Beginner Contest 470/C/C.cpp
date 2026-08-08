#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int curr = 0;
    vector<int> a(n, 0); set<int> s;
    for (int i=0; i<q; i++) { // O(Q)
        int op; cin >> op;

        if (op == 1) {
            int x; cin >> x; x--;
            curr ^= a[x];
            a[x]++; s.insert(x);
            curr ^= a[x];
        } else {
            set<int> next;
            for (int x : s) { // O(N)
                curr ^= a[x];
                if (--a[x]) next.insert(x);
                curr ^= a[x];
            }
            swap(s, next);
        }

        cout << curr << '\n';
    }
}

/*
*/
