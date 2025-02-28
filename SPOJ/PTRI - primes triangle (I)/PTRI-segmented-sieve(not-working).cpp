#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAXN (int)1e8
#define SQN  (int)1e4
#define S    (int)1e4
vector<int> primes;

void setup() {
    vector<int> pprimes = {2};
    vector<char> is_prime(SQN, true);
    for (int i=4; i<=SQN; i+=2)
        is_prime[i] = false;
    
    for (int i=3; i<=SQN; i+=2) {
        if (!is_prime[i]) continue;
        pprimes.push_back(i);
        for (int j=i*i; j<=SQN; j+=i)
            is_prime[j] = false;
    }

    vector<char> block(S);
    int start;
    for (int k=0; (start = k*S) <= MAXN; k++) {
        fill(block.begin(), block.end(), true);
        for (auto p : pprimes) {
            int start_idx = (start + p - 1) / p;
            ll j = (ll)max(start_idx, p) * p - start;
            for (; j<S && start + j<=MAXN; j+=p)
                block[j] = false;
        }

        if (k == 0)
            block[0] = block[1] = false;

        for (int i=0; i<S && start + i <= MAXN; i++) {
            if (block[i])
                primes.push_back(start + i);
        }
    }
}

void solve(int n) {
    auto it = lower_bound(primes.begin(), primes.end(), n);

    if (*it != n) {
        cout << "-1\n";
        return;
    }

    int i = it - primes.begin();

    int a = floor((-1 + sqrt(1 + 8*i)) / 2);
    int b = i - (a*a + a) / 2;
    cout << a + 1 << " " << b + 1 << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setup();

    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        solve(n);
    }
}