#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> cow;



int main() {
    int n;
    cin >> n;

    cow cows[n];
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        cows[i] = {x, y};
    }

    sort(cows, cows+n);
    for (int i=0; i<n; i++) cows[i].first = i;

    auto cmp = [&](const cow &c1, const cow &c2) {
        return c1.second < c2.second;
    };
    sort(cows, cows+n, cmp);
    for (int i=0; i<n; i++) cows[i].second = i;

    int prefix[n+1][n+1] = {};
    
}
