#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;

    int q = 0;
    set<int> s;
    for (int i=0; i<n; i++) {
        int v; cin >> v;
        if (s.find(v) != s.end()) continue;

        s.insert(v);
        if (s.size() == k) {
            q++;
            s.clear();
        }
    }

    if (q >= k) {
        cout << "*" << endl;
    } else {
        int v=1;
        while (s.find(v) != s.end()) { v++; }

        cout << q + 1 << " ";
        for (int i=1; i<=k; i++) {
            if (i == v) {
                i++;
            }
            
            if (i == q + 1) {
                cout << v << " ";
            } else {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}