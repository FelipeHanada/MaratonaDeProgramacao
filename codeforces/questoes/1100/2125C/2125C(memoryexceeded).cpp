#include <bits/stdc++.h>
using namespace std;


// we can precompute all primes using linear sieve
// since the vector lp that is left stores the smaller prime tht can divide n
// we can use it to decide whenever a number is a good number (eq. lp[n] > 9)

// to make queries quicker, build a prefix sum array to count intervals


#define ll long long

constexpr ll MAX_N = 1e18;
vector<ll> primes;
ll lp[MAX_N+1];
ll prefix[MAX_N+1];
void precompute() {
    primes.clear();
    fill_n(lp, MAX_N+1, 0);
    fill_n(prefix, MAX_N+1, 0);
    for (int i=2; i<=MAX_N; i++) {
        if (lp[i] == 0) {
            primes.push_back(i);
            lp[i] = 2;
            if (lp[i] > 9) prefix[i]++;
        }

        for (int j=0; i*primes[j] <= MAX_N; j++) {
            lp[i * primes[j]] = primes[j];
            if (primes[j] > 9) prefix[i * primes[j]]++;
            if (primes[j] == lp[i]) {
                break;
            }
        }
    }


    // computes prefix sum array
    for (int i=1; i<=MAX_N; i++) {
        prefix[i] += prefix[i-1];
    }
}

void solve() {
    int l, r;
    cin >> l >> r;

    cout << prefix[r] - prefix[l-1] << '\n';
}

int main() {
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}