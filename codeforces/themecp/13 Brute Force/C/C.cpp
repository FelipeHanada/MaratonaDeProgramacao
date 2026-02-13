#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map<int, int> a;
        vector<int> b;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            a[x]++;
        }

        int curr = 0;
        while (!a.empty()) {
            int best = 0;
            for (auto [k, v] : a) {
                if ((k|curr) >= (best|curr)) best = k;
            }

            if (!(--a[best])) a.erase(best);
            curr |= best;
            set<int> to_erase;
            for (auto [k, v] : a) {
                if ((curr & k) == k) {
                    to_erase.insert(k);
                }
            }
            for (int k : to_erase) {
                for (int i=0; i<a[k]; i++) b.push_back(k);
                a.erase(k);
            }

            cout << best << ' ';
        }

        for (int x : b) cout << x << ' ';
        cout << '\n';
    }
}