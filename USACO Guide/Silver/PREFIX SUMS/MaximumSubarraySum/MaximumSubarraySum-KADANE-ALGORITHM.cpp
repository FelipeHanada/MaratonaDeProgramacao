#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;


int main() {
    int n;
    cin >> n;
    vl v;
    for (int i=0; i<n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    ll best_sum = INT64_MIN;
    ll current_sum = 0;
    for (const auto &x : v) {
        current_sum = max(x, current_sum + x);
        best_sum = max(best_sum, current_sum);
    }

    cout << best_sum << endl;
}
