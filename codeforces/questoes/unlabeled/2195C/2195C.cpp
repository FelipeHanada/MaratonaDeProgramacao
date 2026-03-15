#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        vector<int> dp1(n), dp2(n); // custo de operações (não) alterando o valor do a[i]
        dp1[0] = 0; dp2[0] = 1;
        for (int i=1; i<n; i++) {
            if (a[i-1] == 7 - a[i] || a[i-1] == a[i]) {
                // se não mexeu nesse, tem que ter mexido no anterior
                dp1[i] = dp2[i-1];

                // se mexeu nesse, então pode vir de qualquer um
                dp2[i] = min(dp1[i-1] + 1, dp2[i-1] + 1);
            } else {
                dp1[i] = min(dp1[i-1], dp2[i-1]);
                dp2[i] = min(dp1[i-1], dp2[i-1]) + 1;
            }
        }

        cout << min(dp1[n-1], dp2[n-1]) << '\n';
    }
}