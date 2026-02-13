#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        pos[x-1] = i;
    }

    // the answer is the largest k such that
    int k=0;
    for (; k<n/2; k++) {
        if (pos[n/2-k-1] > pos[n/2-k] || pos[(n-1)/2+k] > pos[(n-1)/2+k+1])
            break;
    }
    cout << n/2 - k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}