#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    priority_queue<pair<int, char>> pq;
    for (int i=0; i<26; i++) pq.push({ cnt[i], i });

    string out;
    char last = ' ';
    while (pq.top().first) {
        auto [k1, c1] = pq.top(); pq.pop();
        if (c1 == last) {
            auto [k2, c2] = pq.top(); pq.pop();
            if (!k2) {
                cout << "No\n";
                return;
            }

            out.push_back('a' + c2);
            pq.push({ k2-1, c2 });
        }
        out.push_back('a' + c1);
        pq.push({ k1-1, c1 });
        last = c1;
    }

    cout << "Yes\n";
    cout << out << '\n';
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
