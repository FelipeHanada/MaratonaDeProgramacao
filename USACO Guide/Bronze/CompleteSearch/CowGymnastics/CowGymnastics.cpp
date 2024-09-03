#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    int k, n;
    cin >> k >> n;

    set<pair<int, int>> consistent_pairs;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (i != j) consistent_pairs.insert({i, j});

    for (int i=0; i<k; i++) {
        vector<int> seen;

        int c;
        for (int j=0; j<n; j++) {
            cin >> c;

            for (vector<int>::iterator it = seen.begin(); it != seen.end(); it++)
                consistent_pairs.erase({*it, c});

            seen.push_back(c);
        }
    }

    cout << consistent_pairs.size() << endl;
}