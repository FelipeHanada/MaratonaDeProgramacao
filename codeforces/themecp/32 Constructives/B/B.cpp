#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int n, k;
    cin >> n >> k;
    if (n / k <= 2) {
        cout << "-1\n";
        return 0;
    }

    vector<int> ans(n);
    for (int i=0; i<k; i++) ans[i] = (i+1)%k;
    for (int i=k; i<n; i++) ans[i] = i % k;

    for (int x : ans) {
        cout << x + 1 << ' ';
    } cout << '\n';
}
