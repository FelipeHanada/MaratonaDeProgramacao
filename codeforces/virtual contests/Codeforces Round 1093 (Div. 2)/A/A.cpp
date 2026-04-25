#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        set<int> s;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        if (s.size() < n) {
            cout << "-1\n";
        } else {
            sort(a.rbegin(), a.rend());
            for (int x : a) cout << x << ' ';
            cout << '\n';
        }
    }
}
