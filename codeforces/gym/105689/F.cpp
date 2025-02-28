#include <bits/stdc++.h>
using namespace std;


int n, q;
int a[(size_t) (2 * 1e5)];
int c, p, x;
multiset<int> s;

int main() {
    cin >> n >> q;
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
        s.emplace(a[i]);
    }

    for (int i=0; i<q; i++) {
        cin >> c >> p;
        p--;

        if (c == 1) {
            cout << (*s.rbegin()) - a[p] << "\n";
        } else {
            cin >> x;
            s.erase(s.find(a[p]));
            a[p] = x;
            s.insert(x);
        }
    }
}