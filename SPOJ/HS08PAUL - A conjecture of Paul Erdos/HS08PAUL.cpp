#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define uint unsigned int

constexpr ull S = 10000;

bool check_prime(ull p) {
    //  x^2 + y^4 = p, for x and y integers
    //  x^2 = p - y^4
    //  since x^2 > 0 => y^4 <= p
    //  and p - y^4 is a perfect square

    int y4;
    for (int y=0; (y4 = y*y*y*y)<=p; y++) {
        int x = p - y4;
        int sqrtx = round(sqrt(x));
        if (sqrtx*sqrtx == x) {
            return true;
        }
    }
    return false;
}

#define MAXN 9999999
vector<ull> primes;
vector<ull> valid_primes;
void setup() {
    ull sqrtn = sqrt(MAXN);
    primes.push_back(2);
    vector<char> is_prime(sqrtn+1, true);
    for (ull i=4; i<=sqrtn; i+=2)
        is_prime[i] = false;
    for (ull i=3; i<=sqrtn; i+=2) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (ull j = i*i; j<=sqrtn; j+=i)
            is_prime[j] = false;
    }

    int ans = 0;
    vector<char> block(S);
    for (int k=0; k*S<=MAXN; k++) {
        fill(block.begin(), block.end(), true);
        ull start = k*S;

        for (auto p : primes) {
            ull start_idx = (start + p - 1) / p;
            ull j = max(start_idx, p) * p - start;
            for (; j<S && j<=MAXN; j+=p)
                block[j] = false;
        }

        if (k == 0)
            block[0] = block[1] = false;

        for (int i=0; i<S && start + i <= MAXN; i++) {
            if (block[i] && check_prime(start + i))
                valid_primes.push_back(start + i);
        }
    }
}

int solve(ull n) {
    auto it = upper_bound(valid_primes.begin(), valid_primes.end(), n);
    return it - valid_primes.begin();
}

int main() {
    int t;
    cin >> t;
    
    ull n;
    setup();
    for (int i=0; i<t; i++) {
        cin >> n;
        cout << solve(n) << "\n";
    }
}
