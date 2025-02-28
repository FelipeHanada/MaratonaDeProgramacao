#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &a) {
    sort(a.begin(), a.end());

    if (a.front() == a.back()) {
        cout << "-1\n";
        return;
    }

    auto rt = lower_bound(a.begin(), a.end(), a.back());
    cout << rt - a.begin() << " " << a.end() - rt << "\n";

    for (auto it = a.begin(); it != rt; it++)
        cout << *it << " ";
    cout << "\n";

    for (auto it = rt; it != a.end(); it++)
        cout << *it << " ";
    cout << "\n";
}


int main() {
    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        vector<int> a(n);
        for (int j=0; j<n; j++)
            cin >> a[j];
        
        solve(a);
    }
}