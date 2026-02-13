#include <bits/stdc++.h>
using namespace std;


#define ll long long

int n;
int x;
ll ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    multiset<int> pq;
    for (int i=0; i<n; i++) {
        cin >> x;
        pq.emplace(x);

        if (i % 2) {
            pq.extract(pq.begin());
        }
    }

    ans = 0;
    for (int x : pq)
        ans += x;

    cout << ans << '\n';
}
