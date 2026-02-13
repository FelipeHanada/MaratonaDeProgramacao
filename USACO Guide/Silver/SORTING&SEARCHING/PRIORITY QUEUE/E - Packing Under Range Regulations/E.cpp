#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define f first
#define s second

int t, n;
pii lr;

bool cmp(const pii& a, const pii& b) {
    return a > b;
}

void solve() {
    cin >> n;

    priority_queue<pii, vector<pair<int, int>>, bool(*)(const pii&, const pii&)> pq(cmp);
    for (int i=0; i<n; i++) {
        cin >> lr.f >> lr.s;
        pq.emplace(lr);
    }

    vector<int> available(n);
    iota(available.begin(), available.end(), 1);
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();

        auto lb = lower_bound(available.begin(), available.end(), top.f);
        if (lb != available.end() && *lb <= top.s) {
            available.erase(lb);
        } else {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    cin >> t;
    for (int i=0; i<t; i++) {
        solve();
    }
}
