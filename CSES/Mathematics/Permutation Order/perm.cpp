#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    vector<ll> fat(21);
    fat[0] = 1;
    for (int i=1; i<=20; i++) fat[i] = fat[i-1] * i;

    int tt; cin >> tt;
    while (tt--) {
        int op, n;
        cin >> op >> n;
        if (op == 1) {
            ll k; cin >> k; k--;

            vector<int> perm(n);
            deque<int> s;
            for (int i=0; i<n; i++) s.push_back(i);

            for (int i=0; i<n; i++) {
                int to_choose = n - i - 1;
                int j;
                for (j = 0; k >= fat[to_choose]; j++) k -= fat[to_choose];
                perm[i] = s[j];
                s.erase(s.begin() + j);
            }

            for (int x : perm) cout << x + 1 << ' ';
            cout << '\n';

        } else {
            vector<int> perm(n);
            for (int i=0; i<n; i++) cin >> perm[i];
            for (int i=0; i<n; i++) perm[i]--;

            ll k = 0;
            deque<int> s;
            for (int i=0; i<n; i++) s.push_back(i);

            for (int i=0; i<n; i++) {
                int to_choose = n - i - 1;

                int j = 0;
                while (s[j] != perm[i]) j++;

                k += j * fat[to_choose];
                s.erase(s.begin() + j);
            }

            cout << k + 1 << '\n';
        }
    }
}