#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define _f first
#define _s second
using ll = long long;


int main() { _
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        b[i]--;
    }

    int m;
    cin >> m;
    vector<string> s(m);
    for (int i=0; i<m; i++) cin >> s[i];

    vector<set<char>> pos(n);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) if (a[j] == s[i].size()) {
            pos[j].insert(s[i][b[j]]);
        }
    }

    for (int spine = 0; spine < m; spine++) {
        if (s[spine].size() != n) {
            cout << "No\n";
            continue;
        }

        bool good = 1;
        for (int i=0; good && i<n; i++) {
            if (!pos[i].count(s[spine][i])) good = 0;
        }

        cout << (good ? "Yes" : "No") << '\n';
    }
}
