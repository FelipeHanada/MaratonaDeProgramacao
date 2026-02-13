#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin >> x[i];
    }

    multiset<int> left, right;
    ll sum_left = 0, sum_right = 0;
    for (int i=0; i<k; i++) {
        sum_left += x[i];
        left.insert(x[i]);
    }
    while (left.size() > k / 2) {
        sum_right += *left.rbegin();
        right.insert(*left.rbegin());
        sum_left -= *left.rbegin();
        left.extract(*left.rbegin());
    }

    vector<ll> ans;
    ans.push_back(*right.begin() * (left.size() - right.size()) - sum_left + sum_right);
    for (int i=0; i+k<n; i++) {
        if (x[i+k] < *right.begin()) {
            sum_left += x[i+k];
            left.insert(x[i+k]);
        } else {
            sum_right += x[i+k];
            right.insert(x[i+k]);
        }
        
        if (x[i] < *right.begin()) {
            sum_left -= x[i];
            left.extract(x[i]);
        } else {
            sum_right -= x[i];
            right.extract(x[i]);
        }

        while (left.size() > k / 2) {
            sum_right += *left.rbegin();
            right.insert(*left.rbegin());
            sum_left -= *left.rbegin();
            left.extract(*left.rbegin());
        }
        while (right.size() > (k + 1) / 2) {
            sum_left += *right.begin();
            left.insert(*right.begin());
            sum_right -= *right.begin();
            right.extract(*right.begin());
        }

        ans.push_back(*right.begin() * (left.size() - right.size()) - sum_left + sum_right);
    }

    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
