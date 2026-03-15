#include <bits/stdc++.h>
using namespace std;


/*

*/

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    int tt;
    cin >> tt;
    while (tt--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        deque<int> dq;
        int curr = 0;
        for (int i=0; i<n; i++) {
            dq.push_back(a[i]);
            curr += a[i];

            while (b[i]) {
                int delta = min(b[i], dq.front());
                dq.front() -= delta;
                b[i] -= delta;
                curr -= delta;
                if (dq.front() == 0) dq.pop_front();
            }

            if (dq.size() > d) {
                curr -= dq.front();
                dq.pop_front();
            }
        }

        cout << curr << '\n';
    }
}
