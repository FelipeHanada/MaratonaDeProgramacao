#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve() {
    // we can change a subsequence [1, l - 1] with another subsequence of the same size of [l, r]
    // on another hand, we can also change a subsequence [r + 1, n] with another subsequence of the same size of [l, r]
    // choosing elements from both intervals [1, n] - [l, r] is useless
    // since the elements will cancel out (they will not belong to the [l, r] interval)

    int n, l, r;
    cin >> n >> l >> r;
    vector<int> left(l - 1);
    vector<int> v(r - l + 1);
    vector<int> right(n - r);

    for (int i=0; i<l - 1; i++)
        cin >> left[i];
    sort(left.begin(), left.end());

    ll v_sum = 0;
    for (int i=0; i < r - l + 1; i++) {
        cin >> v[i];
        v_sum += v[i];
    }
    sort(v.begin(), v.end());
    
    for (int i=0; i < n - r; i++)
        cin >> right[i];
    sort(right.begin(), right.end());

    ll left_d = 0, right_d = 0;
    for (int i=0; i<min(left.size(), v.size()) && left[i] < v[v.size() - 1 - i]; i++)
        left_d += left[i] - v[v.size() - 1 - i];
        
    for (int i=0; i<min(right.size(), v.size()) && right[i] < v[v.size() - 1 - i]; i++)
        right_d += right[i] - v[v.size() - 1 - i];

    cout << min(v_sum + left_d, v_sum + right_d) << "\n";
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++)
        solve();
}