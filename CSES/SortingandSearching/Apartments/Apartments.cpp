#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    auto ai = a.begin();
    auto bi = b.begin();
    while (ai != a.end() && bi != b.end()) {
        if (*ai < (*bi - k))
            ai++;
        else if (*ai > (*bi + k))
            bi++;
        else {
            ans++;
            ai++; bi++;
        }
    }

    cout << ans << "\n";
}