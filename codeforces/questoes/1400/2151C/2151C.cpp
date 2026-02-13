#include <bits/stdc++.h>
using namespace std;


#define ll long long


void solve() {
    int n;
    cin >> n;
    deque<int> times(2*n);
    for (int i=0; i<2*n; i++) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());

    vector<ll> prefix(2*n+1), even(2*n+1);
    prefix[0] = even[0] = 0;
    for (int i=1; i<=2*n; i++) {
        prefix[i] = prefix[i-1] + times[i-1];
        if (i % 2) even[i] = even[i-1] + times[i-1];
        else even[i] = even[i-1];
    }

    for (int k=1; k<=n; k++) {
        ll even_sum = (even[2*n-k]-even[k]);
        ll odd_sum = (prefix[2*n-k]-prefix[k]) - even_sum;

        cout << ((prefix[2*n]-prefix[2*n-k])-prefix[k]) + (k % 2 ? 1 : -1)*(odd_sum-even_sum) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}