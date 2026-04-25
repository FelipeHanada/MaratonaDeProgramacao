#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    map<int, int> cnt;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        sum += x;
    }

    vector<ll> cand;
    for (auto [k, v] : cnt) cand.push_back(ll(k) * v);
    sort(cand.rbegin(), cand.rend());

    for (int i=0; i<k && i < cand.size(); i++) {
        sum -= cand[i];
    }

    cout << sum << '\n';
}