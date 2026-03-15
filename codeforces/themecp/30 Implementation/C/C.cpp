#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;


int main() { _
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    set<int> setted;
    while (!cnt.empty()) {
        auto [k, c] = *(cnt.begin());
        if (c % 2) setted.insert(k);
        if (c/2) cnt[k+1] += c/2;
        cnt.erase(k);
    }

    int ans = *setted.rbegin() + 1 - setted.size();
    cout << ans << '\n';
}
