#include <bits/stdc++.h>
using namespace std;


#define ll long long

int n;
constexpr int MAX_N = 1e5;
int v[MAX_N];
bool cmp(const int& a, const int& b) {
    return v[a] > v[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> pq(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        pq[i] = i;
    }
    sort(pq.begin(), pq.end(), cmp);

    vector<int> available(n/2);
    iota(available.begin(), available.end(), 0);
    ll ans = 0;
    int counter = 0;
    auto top = pq.begin();
    while (counter < n/2) {
        // try to place it
        auto it = upper_bound(available.begin(), available.end(), *top/2);
        if (it != available.begin()) {
            ans += v[*top];
            counter++;
            available.erase(--it);
        }

        top++;
    }

    cout << ans << '\n';
}
