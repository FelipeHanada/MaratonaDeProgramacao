#include <bits/stdc++.h>
using namespace std;


using ll = long long;

vector<int> primes;

int main() {
    int m, a, b;
    cin >> m >> a >> b;

    vector<bool> sieve(m, 1);
    for (int i=2; i<m; i++) {
        if (sieve[i]) primes.push_back(i);
        for (int j=i*2; j<m; j+=i) sieve[j] = 0;
    }

    map<int, int> mdecomp;
    while (m) {
        for (int p : primes) {
            if (!(m % p)) {
                m /= p;
                mdecomp[p]++;
            }
        }
    }

    set<int> wildcards;
    while (a > 1) {
        for (int p : primes) {
            if (!(a % p)) {
                a /= p;
                wildcards.insert(p);
            }
        }
    }
    while (b > 1) {
        for (int p : primes) {
            if (!(b % p)) {
                b /= p;
                wildcards.insert(p);
            }
        }
    }

    for (int p : wildcards) {
        mdecomp.erase(p);
    }


    auto check = [&](int i, int j) -> bool {
        map<int, int> idecomp, jdecomp;
        while (i > 1) {
            for (int p : primes) {
                if (!(i % p)) {
                    i /= p;
                    idecomp[p]++;
                }
            }
        }
        while (j > 1) {
            for (int p : primes) {
                if (!(j % p)) {
                    j /= p;
                    jdecomp[p]++;
                }
            }
        }

        return 1;
    };

    int ans = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            ans += check(i, j);
        }
    }
    
    cout << ans << '\n';
}
