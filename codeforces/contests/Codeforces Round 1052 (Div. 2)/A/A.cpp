#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> count;
        int x;
        for (int i=0; i<n; i++) {
            cin >> x;
            count[x]++;
        }

        vector<int> a;
        for (auto [key, v] : count) {
            a.push_back(v);
        }
        sort(a.begin(), a.end());

        int best = INT32_MIN;
        for (int i=0; i<a.size(); i++) {
            best = max(best, a[i] * ((int)a.size() - i));
        }

        cout << best << '\n';
    }
}