#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    pair<int, int> v[2*n+1];
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[2*i] = {a, 1};
        v[2*i+1] = {b, -1};
    }

    sort(v, v+2*n);
    int max_customers = INT32_MIN;
    for (int i=0; i<2*n; i++) {
        max_customers = max(max_customers, v[i].second);
        v[i+1].second += v[i].second;
    }

    cout << max_customers << endl;
}
