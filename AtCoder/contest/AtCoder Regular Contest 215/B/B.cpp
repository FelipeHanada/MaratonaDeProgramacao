#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        vector<bool> seen(2*n+1, 0);
        vector<pair<int, int>> pos(2*n+1);
        for (int i=0; i<2*n; i++) {
            cin >> a[i];
            if (seen[a[i]]) pos[a[i]].second = i;
            else pos[a[i]].first = i;
            seen[a[i]] = 1;
        }

        vector<int> color(2*n, -1);
        color[0] = 0;
        color[pos[a[0]].second] = 1;
        for (int i=0; i<2*n; i++) {
            if (color[i] != -1) continue;
            color[i] = color[i-1];
            color[pos[a[i]].second] = 1 - color[i];
        }

        vector<int> ans;
        for (int i=0; i<2*n-1; i++) {
            if (color[i] != color[i+1]) {
                ans.push_back(i);
            }
        }

        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
}
