#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define f first
#define s second
using ll = long long;


/*
abrakadabra
aba

abr => 3
brakadabr => 9
rakadabr => 8
akadabr => 7
kadabr => 6
adabr => 5
dabr => 4
abr => 3
bra => 3
ra => 2
a => 1

3 + 9 + 8 + 7 + 6 + 5 + 4 + 3 + 3 + 2 + 1
*/


int main() { _
    string s, t;
    cin >> s >> t;
    int n = int(s.size()), m = int(t.size());

    vector<queue<int>> q(t.size());
    ll ans = 0;
    int i=0, j = 0;
    while (i < n) {
        while (j < n && q[m-1].empty()) {
            for (int k=0; k<m; k++) {
                if (s[j] == t[k]) {
                    q[k].push(j);
                }
            }
            for (int k=1; k<m; k++) {
                while (!q[k].empty() && (q[k-1].empty() || q[k-1].front() >= q[k].front())) {
                    q[k].pop();
                }
            }
            j++;
        }

        ans += j - 1 - i;
        if (q.back().empty()) ans++;

        for (int k=0; k<m; k++) {
            if (!q[k].empty() && q[k].front() == i) q[k].pop();
        }
        for (int k=1; k<m; k++) {
            while (!q[k].empty() && (q[k-1].empty() || q[k-1].front() >= q[k].front())) {
                q[k].pop();
            }
        }
        i++;
    }

    cout << ans << '\n';
}
