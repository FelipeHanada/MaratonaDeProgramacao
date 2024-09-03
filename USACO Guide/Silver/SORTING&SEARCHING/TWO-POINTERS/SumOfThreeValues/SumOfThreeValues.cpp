#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    pair<int, int> a[n];
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        a[i] = {ai, i+1};
    }
    sort(a, a+n);

    tuple<int, int, int> ans = {0, 0, 0};
    for (int f=0; f<n-2 && get<0>(ans) == 0; f++) {
        int s = f + 1;
        int t = n - 1;

        while (s < t) {
            long long sum = a[f].first + a[s].first + a[t].first;
            if (sum == x) {
                ans = {a[f].second, a[s].second, a[t].second};
                break;
            } else if (sum < x) {
                s++;
            } else {
                t--;
            }
        }
    }

    if (get<0>(ans) != 0) {
        cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}