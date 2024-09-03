#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    map<int, int> towers;
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;

        auto tower = towers.upper_bound(k);
        if (tower != towers.end()) {
            tower->second--;
            if (tower->second <= 0) {
                towers.erase(tower);
            }
        }

        if (towers.find(k) == towers.end()) {
            towers.insert({k, 0});
        }
        towers[k]++;
    }

    int ans = 0;
    for (auto tower : towers) {
        ans += tower.second;
    }

    cout << ans << endl;
}