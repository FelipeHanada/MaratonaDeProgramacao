#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n, m;
    cin >> n >> m;
    set<int> pos;
    bool ok = 1;
    for (int i=0; i<n; i++) {
        int g, s;
        for (int i=0; i<m; i++) {
            char c;
            cin >> c;
            if (c == 'G') g = i;
            else if (c == 'S') s = i;
        }

        ok = ok && (g < s);
        pos.insert(s - g);
    }

    if (!ok) {
        cout << "-1\n";
    } else {
        cout << pos.size() << '\n';
    }
}