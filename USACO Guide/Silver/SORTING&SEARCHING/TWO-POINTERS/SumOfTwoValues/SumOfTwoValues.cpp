#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    pair<int, int> v[n];
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v[i] = {a, i + 1};
    }
    sort(v, v + n);

    int left = 0, right = n - 1;
    pair<int, int> ans = {0, 0};
    while (left < right) {
        int sum = v[left].first + v[right].first;
        if (sum == x) {
            ans = {v[left].second, v[right].second};
            break;
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }

    if (ans.first != 0) {
        cout << ans.first << " " << ans.second << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
