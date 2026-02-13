#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> dp;
    dp.push_back(INT32_MIN);
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        auto lb = lower_bound(dp.begin(), dp.end(), x);
        if (lb == dp.end()) {
            dp.push_back(x);
        } else {
            *lb = x;
        }
    }

    for (int i=0; i<dp.size(); i++) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
    cout << dp.size() - 1 << '\n';
}
