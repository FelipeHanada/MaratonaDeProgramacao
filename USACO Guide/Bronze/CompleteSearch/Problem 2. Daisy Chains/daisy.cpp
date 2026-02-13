#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int p[100];
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }

    int ans = 0, sum;
    for (int i=0; i<n; i++) {
        sum = 0;

        for (int j=i; j<n; j++) {
            sum += p[j];
            if (sum % (j-i+1)) continue;
            
            int avg = sum / (j-i+1);
            for (int k=i; k<=j; k++) {
                if (p[k] == avg) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}
