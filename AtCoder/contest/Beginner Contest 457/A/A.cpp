#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i; i<n; i++) cin >> a[i];
    int x;
    cin >> x;
    x--;
    cout << a[x] << '\n';
}
