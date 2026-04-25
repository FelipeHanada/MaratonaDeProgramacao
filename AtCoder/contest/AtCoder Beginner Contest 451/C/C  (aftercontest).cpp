#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;



int main() {
    int q;
    cin >> q;

    multiset<int> gard;
    while (q--) {
        int t, h;
        cin >> t >> h;

        if (t == 1) {
            gard.insert(h);
        } else {
            gard.erase(gard.begin(), gard.upper_bound(h));
        }

        cout << gard.size() << '\n';
    }
}
