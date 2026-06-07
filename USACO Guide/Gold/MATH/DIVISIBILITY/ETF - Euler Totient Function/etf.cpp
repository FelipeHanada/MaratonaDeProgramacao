#include <bits/stdc++.h>
using namespace std;


constexpr int N = int(1e6);

int main() {
    vector<int> phi(N+1, 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i=2; i<=N; i++) {
        if (phi[i] != i) continue; // i is not prime
        for (int j=i; j<=N; j+=i) {
            phi[j] -= phi[j] / i;
        }
    }

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << phi[n] << '\n';
    }
}