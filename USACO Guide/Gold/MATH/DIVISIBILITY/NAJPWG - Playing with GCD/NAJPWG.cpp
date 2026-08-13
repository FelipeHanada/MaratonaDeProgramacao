#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = int(1e5);

int main() {
    vector<int> phi(N+1);
    iota(phi.begin(), phi.end(), 0);
    for (int i=2; i<=N; i++) if (phi[i] == i) {
        // i is prime
        for (int j=i; j<=N; j+=i) {
            phi[j] -= phi[j]/i;
        }
    }

    vector<ll> prefix(N+1, 0);
    for (int i=1; i<=N; i++) {
        prefix[i] = prefix[i-1] + i - phi[i];
    }

    int tt;
    cin >> tt;
    for (int t = 1; t<=tt; t++) {
        int n; cin >> n;
        cout << "Case " << t << ": " << prefix[n] << '\n';
    }
}
