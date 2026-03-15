#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        if (count(a.begin(), a.end(), a[0]) == n) {
            cout << 0 << '\n';
            continue;
        }
        if (count(a.begin(), a.end(), 1)) {
            cout << "-1\n";
            continue;
        }

        map<int, set<int>> pos;
        for (int i=0; i<n; i++) pos[a[i]].insert(i);

        vector<pair<int,int>> steps;
        while (pos.size() > 1) {
            auto it = (++pos.rbegin());
            int k = it->first;
            int j = *(it->second.begin());

            for (auto i : pos.rbegin()->second) {
                steps.push_back({ i, j });
            }

            for (auto i : pos.rbegin()->second) {
                pos[(pos.rbegin()->first + k - 1) / k].insert(i);
            }

            pos.erase(pos.rbegin()->first);
        }

        cout << steps.size() << '\n';
        for (auto [i, j] : steps) {
            cout << i+1 << ' ' << j+1 << '\n';
        }
    }
}
