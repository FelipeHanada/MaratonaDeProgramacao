#include <bits/stdc++.h>
using namespace std;

int last_true(int low, int high, function<bool(int)> f) {
    low--;
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
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    int n, t;
    cin >> n >> t;

    vector<int> d;
    for (int i=0; i<n; i++) {
        int di; cin >> di;
        d.push_back(di);
    }

    auto ok_show = [&](int n_minus_k) {
        priority_queue<int> exit_times;
        int k = n - n_minus_k;
        for (int i=0; i<k; i++) {
            exit_times.emplace(-d[i]);
        }
        for (int i=k; i<n; i++) {
            auto first_exit = -exit_times.top();
            exit_times.pop();
            exit_times.emplace(-(d[i] + first_exit));
        }

        while (exit_times.size() > 1) {
            exit_times.pop();
        }

        return -exit_times.top() <= t;
    };

    cout << n - last_true(0, n-1, ok_show) << endl;
}
