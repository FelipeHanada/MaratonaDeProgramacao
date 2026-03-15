#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
    string s;
    cin >> s;
    pair<int, int> pos = {0, 0};
    set<pair<int, int>> seen; seen.insert({0, 0});
    for (char c : s) {
        if (c == 'L') {
            pos.first--;
        } else if (c == 'R') {
            pos.first++;
        } else if (c == 'U') {
            pos.second++;
        } else {
            pos.second--;
        }

        int cnt = 0;
        if (seen.count({pos.first+1, pos.second})) cnt++;
        if (seen.count({pos.first-1, pos.second})) cnt++;
        if (seen.count({pos.first, pos.second+1})) cnt++;
        if (seen.count({pos.first, pos.second-1})) cnt++;

        if (seen.count(pos) || cnt > 1) {
            cout << "BUG\n";
            return 0;
        }

        seen.insert(pos);
    }
    cout << "OK\n";
}
