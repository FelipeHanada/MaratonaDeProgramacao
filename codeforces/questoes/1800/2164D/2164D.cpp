#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; string s, t;
        cin >> n >> k >> s >> t;

        vector<array<int,2>> a;
        bool ok = 1;
        int i=n-1, j=n-1;
        while (ok && j >= 0) {
            i = min(i, j);

            while (i >= 0 && s[i] != t[j]) i--;
            if (i < 0) ok = 0;
            a.push_back({i, j});

            j--;
        }


        if (!ok) {
            cout << "-1\n";
            continue;
        }

        vector<string> ans;
        while (k-- && s.compare(t)) {
            string next = s;

            for (auto& [i, j] : a) if (i < j) {
                next[i+1] = s[i];
                i++;
            }

            s = next;
            ans.push_back(s);
        }

        if (s.compare(t)) {
            cout << "-1\n";
        } else {
            cout << ans.size() << '\n';
            for (string x : ans) {
                cout << x << '\n';
            }
        }
    }
}