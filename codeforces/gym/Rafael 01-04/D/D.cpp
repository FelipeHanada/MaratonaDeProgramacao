#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, string>>> a(m);
    for (int i=0; i<n; i++) {
        string s; int x, y;
        cin >> s >> x >> y;
        a[x-1].push_back({y, s});
    }

    for (int i=0; i<m; i++) sort(a[i].rbegin(), a[i].rend());

    for (int i=0; i<m; i++) {
        if (a[i].size() > 2 && a[i][1].first == a[i][2].first) {
            cout << "?\n";
        } else {
            cout << a[i][0].second << ' ' << a[i][1].second << '\n';
        }
    }
}