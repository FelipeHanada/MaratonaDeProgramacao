#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n);
        for (int i=0; i<n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;

        vector<int> diff(n+1, 0);
        for (int i=0; i<n; i++) {
            if (i == p[i]-1) continue;
            diff[min(i, p[i]-1)]++;
            diff[max(i, p[i]-1)]--;
        }
        for (int i=1; i<=n; i++) diff[i] += diff[i-1];

        set<int> bad;
        char last = 'R';
        for (int i=0; i<n; i++) {
            if (s[i] == 'R' && last == 'L' && diff[i-1]) {
                bad.insert(i-1);
            }
            last = s[i];
        }

        while (q--) {
            int x;
            cin >> x;
            x--;
            
            if (s[x] == 'L') {
                // () L () -> () R ()
                if (s[x+1] == 'R') bad.erase(x);
                if (s[x-1] == 'L' && diff[x-1]) bad.insert(x-1);
                s[x] = 'R';
            } else {
                // () R () -> () L ()
                if (s[x-1] == 'L') bad.erase(x-1);
                if (s[x+1] == 'R' && diff[x]) bad.insert(x);
                s[x] = 'L';
            } 

            cout << (bad.empty() ? "YES" : "NO") << '\n';
        }
    }
}