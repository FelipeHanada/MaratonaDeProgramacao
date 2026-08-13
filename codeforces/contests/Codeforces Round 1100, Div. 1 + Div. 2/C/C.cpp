#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        vector<int> moves;
        int mod = 1;
        for (int i=n-1; i>=0; i--) {
            if (a[i] * mod > 0) {
                mod *= -1;
                moves.push_back(i);
            }
        }

        cout << moves.size() << '\n';
        for (int x : moves) cout << x + 1 << ' ';
        cout << '\n';
    }
}
