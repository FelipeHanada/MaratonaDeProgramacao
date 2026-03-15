#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n;
    cin >> n;
    map<int, set<int>> a;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].insert(y);
    }

    if (a.size() == 1) {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    while (!a.empty()) {
        ans++;
        set<int> rows;
        queue<int> q;
        for (int r : a.begin()->second) q.push(r);

        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            set<int> to_del;
            for (auto [c, s] : a) {
                if (s.count(curr)) to_del.insert(c);
            }

            for (int x : to_del) {
                for (int y : a[x]) {
                    if (rows.count(y) == 0) q.push(y);
                    rows.insert(y);
                }
                a.erase(x);
            }
        }
    }
    ans--;

    cout << ans << '\n';
}