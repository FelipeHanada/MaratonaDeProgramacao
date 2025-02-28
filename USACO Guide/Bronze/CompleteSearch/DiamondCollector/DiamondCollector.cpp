#include <bits/stdc++.h>
using namespace std;


int n, k;
int x;
map<int, int> m;
int curr, best;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> x;
        if (m.find(x) == m.end())
            m.insert({x, 0});
        m[x]++;
    }

    best = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        curr = 0;
        for (auto it2 = it; it2 != m.end(); it2++) {
            if (abs(it2->first - it->first) <= k)
                curr += it2->second;
        }

        best = max(best, curr);
    }

    cout << best << "\n";
}
