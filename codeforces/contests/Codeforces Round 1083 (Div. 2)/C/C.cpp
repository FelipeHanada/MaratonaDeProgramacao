#include <bits/stdc++.h>
using namespace std;



using ll = long long;
#define _1 first
#define _2 second


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i=0; i<n; i++) {
        int l; cin >> l;
        vector<int> b;
        for (int j=0; j<l; j++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        reverse(b.begin(), b.end());
        set<int> seen;
        for (int x : b) {
            if (seen.count(x)) continue;
            seen.insert(x);
            a[i].push_back(x);
        }
    }

    set<int> setted;
    auto le = [&](int i, int j) -> bool {
        int p = 0, q = 0;
        while (p < a[i].size() && setted.count(a[i][p])) p++;
        while (q < a[j].size() && setted.count(a[j][q])) q++;
        
        while (p < a[i].size() && q < a[j].size()) {
            if (a[i][p] < a[j][q]) return 1;
            else if (a[i][p] > a[j][q]) return 0;
            p++; q++;

            while (p < a[i].size() && setted.count(a[i][p])) p++;
            while (q < a[j].size() && setted.count(a[j][q])) q++;
        }

        return p == a[i].size();
    };

    set<int> avl; for (int i=0; i<n; i++) avl.insert(i);
    vector<int> ans;
    while (avl.size() > 0) {
        auto it = avl.begin();
        int best = *(it);
        it++;
        for (; it != avl.end(); it++) {
            if (le(*it, best)) best = *it;
        }

        for (int x : a[best]) {
            if (setted.count(x)) continue;
            setted.insert(x);
            ans.push_back(x);
        }
        
        avl.erase(best);
    }

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) solve();
}
