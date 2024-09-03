#include <bits/stdc++.h>
using namespace std;


int last_true(int low, int high, function<bool(int)> f) {
    // low: last true found
    // high: last potential true (prev to the last false found)

    low--; high--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (f(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    function<bool(int)> increase_mean_to = [&](int x) {
        int k_required = 0;
        for (int i=(n-1)/2; i<n && k_required <= k; i++) {
            k_required += max(0, x - v[i]);
        }
        return k_required <= k;
    };

    cout << last_true(v[(n-1)/2], 2e9 + 1, increase_mean_to) << endl;
}
