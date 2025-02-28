#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define N (ull)100000000
#define S (ull)10000

void solve() {
    ull sqrtN = sqrt(N);
    vector<ull> primes = {2};
    vector<char> is_prime(sqrtN+1, true);
    for (int i=4; i <= sqrtN; i+=2)
        is_prime[i] = false;
    for (int i=3; i <= sqrtN; i+=2) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for(int j=i*i; j<=sqrtN; j+=i)
            is_prime[j] = false;
    }

    ull count = 0;
    vector<char> block(S);
    for (int k=0; S*k < N; k++) {
        fill(block.begin(), block.end(), true);
        ull start = S*k;

        for (auto p : primes) {
            ull start_idx = (start + p - 1) / p;

            int j = max(start_idx, p) * p - start;
            for (; j<S; j+=p)
                block[j] = false;
        }

        if (k == 0)
            block[0] = block[1] = false;
        
        for (int i=0; i < S && start + i <= N; i++) {
            if (!block[i]) continue;

            count++;
            if (count % 100 == 1)
                cout << start + i << "\n";
        }
    }
}

int main() {
    solve();
}
