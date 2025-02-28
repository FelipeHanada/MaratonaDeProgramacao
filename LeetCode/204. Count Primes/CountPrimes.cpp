#include <bits/stdc++.h>
using namespace std;


int solve(int n) {
    int sqrtn = sqrt(n);
    vector<int> primes = {2};
    vector<bool> is_prime(sqrtn + 1, true);

    for (int i=4; i<=sqrtn; i+=2)
        is_prime[i] = false;
    for (int i=3; i<=sqrtn; i+=2) {
        if (!is_prime[i]) continue;

        primes.push_back(i);
        for (int j=i*i; j<=sqrtn; j+=i)
            is_prime[j] = false;
    }


    const int S = 10000;
    int ans = 0;
    vector<char> block(S);
    for (int k=0; S*k <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = S * k;

        for (auto p : primes) {
            int start_i = (start + p - 1) / p;
            //  index of the first multiple of p grater than start

            int j = max(start_i, p) * p - start;
            //  first multiple of p greater or equal to start and p*p

            for (; j<S; j+=p)
                block[j] = false;
        }

        if (k == 0)
            block[0] = block[1] = false;
        
        for (int i=0; i < S && start + i < n; i++) {
            if (block[i])
                ans++;
        }
    }

    return ans;
}


int main() {
    int n;
    cin >> n;

    cout << solve(n) << "\n";
}