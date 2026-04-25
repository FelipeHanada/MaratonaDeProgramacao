#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        set<int> opens;
        for (int i=0; i<n; i++) {
            int curr = i + 1; // 1-indexado
            opens.erase(curr);
            opens.insert(a[i]);

            ans = max(ans, int(opens.size()));
        }

        cout << ans << '\n';
    }
}
