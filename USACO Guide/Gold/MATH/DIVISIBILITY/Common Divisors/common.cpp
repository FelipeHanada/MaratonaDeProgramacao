#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    // gcd is bounded by maxA
    // g can be a gcd iff. g | xi and g | xj   for some i != j
    vector<int> cnt(a.back() + 1, 0);
    for (int i=0; i<n; i++) cnt[a[i]]++;
    int ans = 1;
    for (int g = 2; g <= a.back(); g++) {
        for (int j=2*g; j < cnt.size(); j+=g) {
            cnt[g] += cnt[j];
        }

        if (cnt[g] > 1) ans = max(ans, g);
    }

    cout << ans << '\n';
}
