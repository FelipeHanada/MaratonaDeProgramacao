#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;

    unordered_set<int> zeros;
    unordered_set<int> seen;
    for (int i=1; i<=n; i++) seen.insert(i);
    vector<int> perm(n);
    for (int i=0; i<n; i++) {
        cin >> perm[i];
        seen.insert(perm[i]);
        if (!perm[i]) zeros.insert(i);
        seen.erase(perm[i]);
    }
    if (zeros.size() == 1) perm[*zeros.begin()] = *seen.begin();

    int i=0, j=n-1;
    while (i<n && !((perm[i] != i+1 && perm[i] != 0) || perm[i] == 0)) {
        i++;
    }
    while (j>=0 && !((perm[j] != j+1 && perm[j] != 0) || perm[j] == 0)) {
        j--;
    }

    cout << (i<=j ? j-i+1 : 0) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}