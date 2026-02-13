#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }

    multiset<int> low, high;
    for (int i=0; i<k; i++) {
        low.insert(x[i]);
    }
    while (low.size() > (k - 1) / 2) {
        high.insert(*low.rbegin());
        low.extract(*low.rbegin());
    }

    vector<int> ans;
    ans.push_back(*high.begin());
    for (int i=0; i+k<n; i++) {
        if (x[i] < *high.begin()) {
            low.extract(x[i]);
        } else {
            high.extract(x[i]);
        }
        if (x[i+k] < *high.begin()) {
            low.insert(x[i+k]);
        } else {
            high.insert(x[i+k]);
        }

        while (high.size() > k / 2 + 1) {
            low.insert(*high.begin());
            high.extract(*high.begin());
        }
        while (low.size() > (k - 1) / 2) {
            high.insert(*low.rbegin());
            low.extract(*low.rbegin());
        }
        ans.push_back(*high.begin());
    }

    for (int i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}
