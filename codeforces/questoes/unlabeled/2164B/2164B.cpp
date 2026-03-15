#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        auto check = [&](int i, int j) -> bool {
            if (i > j) swap(i, j);
            return (a[j]%a[i])%2 == 0;
        };

        vector<int> evens, odds;
        for (int i=0; i<n; i++) {
            if (a[i] % 2 == 0) evens.push_back(i);
            else odds.push_back(i);
        }

        if (evens.size() > 1) {
            cout << a[evens.front()] << ' ' << a[evens.back()] << '\n';
            continue;
        }

        pair<int, int> ans = { -1, -1 };
        if (evens.size() == 1) {
            for (int i=0; i<evens.front() && ans.first == -1; i++) {
                if (check(i, evens.front())) {
                    ans = { i, evens.front() };
                }
            }

            if (ans.first != -1) {
                cout << a[ans.first] << ' ' << a[ans.second] << '\n';
                continue;
            }
        }

        for (int i=0; i<odds.size()-1 && ans.first == -1; i++) {
            if (a[odds[i+1]] < 2 * a[odds[i]]) ans = { odds[i], odds[i+1] };
        }

        if (ans.first != -1) {
            cout << a[ans.first] << ' ' << a[ans.second] << '\n';
            continue;
        }

        for (int i=0; i<odds.size(); i++) {
            for (int j=i+1; j<odds.size() && ans.first == -1; j++) {
                if (check(odds[i], odds[j])) ans = { odds[i], odds[j] };
            }
        }

        if (ans.first != -1) {
            cout << a[ans.first] << ' ' << a[ans.second] << '\n';
            continue;
        }

        cout << "-1\n";
    }
}
