#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 2e5;
ll diff[MAX_N+2];

int main() {
    int n, q;
    cin >> n >> q;

    priority_queue<int> pq;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        pq.emplace(x);
    }

    int l, r;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }
    priority_queue<int> pq_freq;
    for (int i=1; i<=n; i++) {
        diff[i] += diff[i-1];
        pq_freq.emplace(diff[i]);
    }

    ll ans = 0;
    while (!pq.empty()) {
        ans += (ll)pq.top() * pq_freq.top();
        pq.pop(); pq_freq.pop();
    }

    cout << ans << '\n';
}
