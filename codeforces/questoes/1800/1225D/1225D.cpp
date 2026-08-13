#include <bits/stdc++.h>
using namespace std;

constexpr int N = int(1e6);
using ll = long long;

constexpr int md1 = int(1e9)+7;
constexpr int md2 = int(1e9)+9;
int add(int a, int b, int md) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int sub(int a, int b, int md) {
    a -= b;
    if (a < 0) a += md;
    return a;
}
int mult(int a, int b, int md) {
    return (ll(a) * b) % md;
}


int main() {
    vector<int> sieve(N+1, 0);
    for (int i=2; i<=N; i++) {
        if (sieve[i]) continue;
        for (int j=i; j<=N; j+=i) if (!sieve[j]) {
            sieve[j] = i;
        }
    }

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    map<pair<int, int>, int> m;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;

        int y1 = 1, search1 = 1;
        int y2 = 1, search2 = 1;
        int cnt = k, last = -1;
        while (x > 1) {
            int p = sieve[x];
            if (p == last) {
                cnt++;
            } else {
                for (int i=0; i<cnt%k; i++) {
                    y1 = mult(y1, last, md1);
                    y2 = mult(y2, last, md2);
                }
                for (int i=0; i<((k-cnt)%k + k) % k; i++) {
                    search1 = mult(search1, last, md1);
                    search2 = mult(search2, last, md2);
                }
                last = p;
                cnt = 1;
            }
            x /= p;
        }
        for (int i=0; i<cnt%k; i++) {
            y1 = mult(y1, last, md1);
            y2 = mult(y2, last, md2);
        }
        for (int i=0; i<((k-cnt)%k + k) % k; i++) {
            search1 = mult(search1, last, md1);
            search2 = mult(search2, last, md2);
        }

        ans += m[{ search1, search2 }];
        m[{ y1, y2 }]++;
    }

    cout << ans << '\n';
}