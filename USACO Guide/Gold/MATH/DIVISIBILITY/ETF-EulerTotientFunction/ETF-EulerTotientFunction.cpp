//  https://www.spoj.com/problems/ETF/
#include <bits/stdc++.h>
using namespace std;

constexpr int N_MAX = 1e6;
int phi[N_MAX + 1];

void calc_phi() {
    iota(phi, phi + N_MAX + 1, 0);
    
    for (int i=2; i<=N_MAX; i++) {
        if (phi[i] != i) continue;

        for (int j=i; j<=N_MAX; j+=i) {
            phi[j] -= phi[j] / i;
        }
    }
}

int main() {
    int t; cin >> t;

    calc_phi();
    for (int i=0; i<t; i++) {
        int n; cin >> n;
        cout << phi[n] << endl;
    }
}
