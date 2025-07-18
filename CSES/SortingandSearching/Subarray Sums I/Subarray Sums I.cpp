#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    int x[n];
    for (int i=0; i<n; i++) cin >> x[i];

    int i=0, j=0;
    int sum=0;
    int ans=0;
    while (j < n || sum >= k) {
        if (sum < k) {
            sum += x[j++];
        } else if (sum > k) {
            sum -= x[i++];
        } else {
            ans++;
            sum -= x[i++];
        }
    }

    cout << ans << '\n';
}