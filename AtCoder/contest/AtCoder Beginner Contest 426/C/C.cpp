#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    map<int, int> m;
    for (int i=1; i<=n; i++) m[i] = 1;

    int x, y;
    while (q--) {
        cin >> x >> y;
        int ans = 0; // quantidade de computadores melhorados no nivel y
        unordered_set<int> to_del;
        for (auto it = m.begin(); it != m.end() && it->first <= x; it++) {
            to_del.insert(it->first);
        }

        for (int i : to_del) {
            ans += m[i];
            m.erase(i);
        }

        cout << ans << '\n';
        m[y] += ans;
    }
}
