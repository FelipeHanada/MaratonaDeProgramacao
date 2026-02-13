#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    deque<int> l, g;
    for (int i=0; i<n; i++) {
        char c; int x;
        cin >> c >> x;
        if (c == 'L') l.push_back(x);
        else g.push_back(x);
    }
    sort(l.begin(), l.end());
    sort(g.begin(), g.end());

    int ans = g.size();
    for (int i=0; i<g.size(); i++) {
        // x is atleast g[i], then it cannot be lesser than g[i]
        ans = min(ans, i + (int)distance(l.begin(), lower_bound(l.begin(), l.end(), g[g.size()-1-i])));
    }

    cout << ans << '\n';
}
