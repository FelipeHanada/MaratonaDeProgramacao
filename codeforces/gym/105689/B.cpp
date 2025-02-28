#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int ans = 0;
    do {
        if (v[n-1] == 0)
            continue;

        int sum = 0;
        int b = 1;
        for (int i=0; i<n; i++) {
            sum += v[i] * b;
            b *= 10;
        }
        
        if (sum % 12 == 9)
            ans++;
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
}
