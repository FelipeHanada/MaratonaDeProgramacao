#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    map<int, int> ocurr;
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
        ocurr[b[i]]++;
    }

    for (auto [x, k] : ocurr) {
        if (k%x) {
            cout << "-1\n";
            return;
        }
    }


    int id = 1;
    map<int, int> a;
    for (int i=0; i<n; i++) {
        if (!(ocurr[b[i]] % b[i])) {
            a[b[i]] = id++;
        }

        cout << a[b[i]] << ' ';
        ocurr[b[i]]--;
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}