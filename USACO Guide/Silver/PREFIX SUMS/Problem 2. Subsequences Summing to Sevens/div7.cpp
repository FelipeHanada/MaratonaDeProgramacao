#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX_N = 50000;
int n;
ll prefix[MAX_N+1];

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    cin >> n;
    prefix[0] = 0;
    for (int i=0; i<n; i++) {
        cin >> prefix[i+1];
        prefix[i+1] = (prefix[i+1] + prefix[i]) % 7;
    }

    int best = 0;
    for (int i=0; i<n; i++) {
        for (int j=1+i+best; j<=n; j++) {
            if ((prefix[j] - prefix[i]) % 7 == 0) {
                best = max(best, j - i);
            }
        }
    }

    cout << best << '\n';
}
