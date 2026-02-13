#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;

    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        int a[n];

        for (int j=0; j<n; j++) cin >> a[j];
        sort(a, &a[n]);

        int k = 1;
        int med = ceil(n / 2.f) - 1;

        int right = med + 1;
        while (right < n && a[right++] == a[med]) k++;

        cout << k << endl;
    }
}
