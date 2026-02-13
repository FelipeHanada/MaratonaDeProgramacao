#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n, q;
    cin >> n >> q;
    deque<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    while (q--) {
        int x;
        cin >> x;
        int ans = 0;
        auto it = a.begin();
        while (*it != x) {
            it++;
            ans++;
        }
        a.erase(it);
        a.push_front(x);

        cout << ans + 1 << ' ';
    }
    cout << '\n';
}