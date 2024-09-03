#include <bits/stdc++.h>
using namespace std;



int main() {
    freopen("haybales.in", "r", stdin);  
    freopen("haybales.out", "w", stdout);

    int n, q; cin >> n >> q;

    vector<int> v;
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());

    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        auto left = lower_bound(v.begin(), v.end(), a);
        auto right = lower_bound(left, v.end(), b+1);
        cout << right - left << endl;
    }
}
