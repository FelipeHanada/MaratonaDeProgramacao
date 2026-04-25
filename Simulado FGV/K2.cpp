#include <bits/stdc++.h>
using namespace std;


constexpr int md = int(1e9) + 7; 
using ll = long long;

int add(int a, int b) {
    a += b;
    if (a > md) a -= md;
    return a;
}

int mult(int a, int b) {
    return ((ll)a * b) % md;
}

int binpow(int a, int b) {
    int ans = 1;
    int p = a;
    while (b) {
        if (b & 1) ans = mult(ans, p);
        b >>= 1;
        p = mult(p, p);
    }

    return ans;
}

int p2(int x) {
    int ans = 1;
    int p = 2;
    while (x) {
        if (x & 1) ans = (ll(ans) * p) % md;
        x >>= 1;
        p = (ll(p) * p) % md;
    }

    return ans;
}


int main() {
    vector<int> primes;
    vector<bool> sieve(int(1e6)+1, 0);
    for (int i=2; i<=int(1e6); i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (int j=i; j<=int(1e6); j+=i) {
            sieve[j] = 1;
        }
    }



    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        if (*lower_bound(primes.begin(), primes.end(), n) == n) {
            cout << "2\n";
            continue;
        }

        int ans = 2;
        map<int, pair<int, int>> fat;
        for (int p : primes) {
            pair<int,int> q = {0, 1};
            while (n % p == 0) {
                q.first++;
                q.second = mult(q.second, p);
                n /= p;
            }
            if (q.first) fat[p] = q;
            if (n == 1) break;
        }

        if (fat.size() == 1) {
            ans = binpow(2, binpow(fat.begin()->first, fat.begin()->second.first - 1));
        } else {
            ans = 2;
            for (auto [p, q] : fat) {
                ans = add(ans, add(add(binpow(2, q.second), -2), md));
            }
        }

        cout << ans << '\n';
    }
}
