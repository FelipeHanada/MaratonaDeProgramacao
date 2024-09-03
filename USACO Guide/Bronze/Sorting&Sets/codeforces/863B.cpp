#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    int weights[2*n];
    for (int i=0; i<n*2; i++) cin >> weights[i];

    sort(weights, weights + 2*n);

    int min_total_instability = INT32_MAX;
    for (int i=0; i<2*n-1; i++) {
        for (int j=i+1; j<2*n; j++) {
            int total_instability = 0;

            if (i == 6 && j == 7) {
                cout << "teste" << endl;
            }

            int p = 0;
            int a[n-1] = { 0 };
            for (int k=0; k<n-1; k++) {
                while (p == i || p == j) p++;
                a[k] = weights[p];
                p++;
            }
            p++;
            for (int k=0; k<n-1; k++) {
                while (p == i || p == j) p++;
                total_instability += abs(a[k] - weights[p]);
                p++;
            }

            min_total_instability = min(min_total_instability, total_instability);
        }
    }

    cout << min_total_instability << endl;
}
