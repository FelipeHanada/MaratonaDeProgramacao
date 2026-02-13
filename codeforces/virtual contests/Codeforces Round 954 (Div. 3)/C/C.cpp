#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    deque<int> indexes;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        indexes.push_back(x-1);
    }
    sort(indexes.begin(), indexes.end());
    deque<char> chars;
    for (int i=0; i<m; i++) {
        char x;
        cin >> x;
        chars.push_back(x);
    }
    sort(chars.begin(), chars.end());

    while (!indexes.empty()) {
        while (indexes.size() > 1 && indexes[0] == indexes[1]) {
            indexes.pop_front();
            chars.pop_back();
        }

        s[indexes.front()] = chars.front();
        indexes.pop_front();
        chars.pop_front();
    }

    cout << s << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}