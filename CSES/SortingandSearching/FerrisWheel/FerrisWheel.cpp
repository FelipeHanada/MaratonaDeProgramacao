#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n;
    ll x;
    cin >> n >> x;
    
    ll p[n];
    for (int i=0; i<n; i++)
        cin >> p[i];
    sort(p, p + n);

    int ans = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        ll curr_x = x - p[j];
        j--;

        if (p[i] <= curr_x)
            i++;

        ans++;
    }

    if (i == j)
        ans++;

    cout << ans << "\n";
}