#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        map<int, deque<int>> a;
        for (int i=0; i<k; i++) {
            int ref;
            cin >> ref;
            for (int j=1; j<n; j++) {
                int x;
                cin >> x;
                a[ref].push_back(x);
            }
        }

        bool ok = 1;
        int cnt = 0;
        while (ok && cnt < n) {
            pair<int,int> big1 = {-1, -1};
            pair<int,int> big2 = {-1, -1};
            for (auto [ref, dq] : a) {
                if (dq.empty()) continue;
                if (big1.second == dq[0]) big1.first++;
                if (big2.second == dq[0]) big2.first++;
                if (big2.first == -1) big2 = { 1, dq[0] };
                if (big2 > big1) swap(big1, big2);
            }

            if (big1.first == -1) break;

            if (big1.first < k) {
                ok = 0;
                break;
            }

            cnt++;
            for (auto it = a.begin(); it != a.end(); it++) {
                if (it->second.empty()) continue;
                if (it->second[0] == big1.second) it->second.pop_front();
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
