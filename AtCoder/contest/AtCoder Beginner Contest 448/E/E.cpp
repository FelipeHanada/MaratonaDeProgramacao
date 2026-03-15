#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;

constexpr int N = int(1e6);
constexpr int MOD = 10007;

int p10modM[N+1], p10mod10007[N+1];
array<array<int,N+1>, 10> pmodM, pmod10007;

int inv(int x) {
    return x <= 1 ? x : MOD - ll(MOD/x) * inv(MOD%x) % MOD;
}

int main() {
    int k, m;
    cin >> k >> m;
    vector<array<int,2>> a(k);
    for (int i=0; i<k; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    p10modM[0] = 1; for (int i=1; i<=int(1e6); i++) p10modM[i] = (p10modM[i-1]*10) % m;
    p10mod10007[0] = 1; for (int i=1; i<=int(1e6); i++) p10mod10007[i] = (p10mod10007[i-1]*10) % MOD;

    fill(pmodM[0].begin(), pmodM[0].end(), 0);
    fill(pmod10007[0].begin(), pmod10007[0].end(), 0);
    for (int i=1; i<=9; i++) {
        pmodM[i][0] = pmod10007[i][0] = 0;
        for (int j=1; j<=N; j++) {
            pmodM[i][j] = (ll(pmodM[i][j-1]) * 10 + i) % m;
            pmod10007[i][j] = (ll(pmod10007[i][j-1]) * 10 + i) % MOD;
        }
    }

    // small = N mod M e big = N mod 10007
    int small = 0, big = 0;
    for (int i=0; i<k; i++) {
        while (a[i][1]) {
            int delta = min(a[i][1], N);            
            small = ((ll)small * p10modM[delta]) % m;
            big = ((ll)big * p10mod10007[delta]) % MOD;
            small = (small + pmodM[a[i][0]][delta]) % m;
            big = (big + pmod10007[a[i][0]][delta]) % MOD;
            a[i][1] -= delta;
        }
    }

    cout << (ll((big - small + MOD) % MOD) * inv(m)) % MOD << '\n';
}
