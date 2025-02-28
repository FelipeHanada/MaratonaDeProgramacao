#include <bits/stdc++.h>
using namespace std;



constexpr int MAXN = 10e5;
vector<int> primes;
void sieve() {
    array<bool, MAXN+1> is_prime;
    fill(is_prime.begin(), is_prime.end(), true);

    primes.push_back(2);
    for (int i=4; i<= MAXN; i+=2)
        is_prime[i] = false;
    
    int i=3;
    for (; i * i <= MAXN; i+=2) {
        if (!is_prime[i])
            continue;
        
        primes.push_back(i);
        for (int j=2*i; j <= MAXN; j+=i)
            is_prime[j] = false;
    }
    for (; i <= MAXN; i+=2) {
        if (is_prime[i])
            primes.push_back(i);
    }
}

int solve(vector<int> &nums) {
    sieve();

    int ans = 0;
    for (auto x : nums) {
        int p = x;

        int d[2];
        int count = 0;

        for (auto it = primes.begin(); it != primes.end() && (*it) <= p && count < 2; it++) {
            if (p % (*it) == 0) {
                d[count] = (*it);
                count++;
                p /= (*it);

                if (p % (*it) == 0) {
                    if (d[0] == (*it) && (*it) * (*it) == p) {
                        p = 1;
                        d[1] = (*it);
                        count++;
                    }
                    break;
                }
            }
        }

        if (p > 1 || count < 2)
            continue;

        if (d[0] == d[1])
            ans += 1 + d[0] + d[0]*d[1] + x;
        else
            ans += 1 + d[0] + d[1] + x;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin >> v[i];

    cout << solve(v) << "\n";
}