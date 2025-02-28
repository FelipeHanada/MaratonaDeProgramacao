#include <bits/stdc++.h>
using namespace std;


#define MAXN 3000
vector<int> prime_divisors(MAXN+1);
void setup() {
    prime_divisors[0] = prime_divisors[1] = 0;
    prime_divisors[2] = 1;

    for (int i=4; i<=MAXN; i+=2)
        prime_divisors[i]++;

    for (int i=3; i<=MAXN; i+=2) {
        if (prime_divisors[i]) continue;
        prime_divisors[i] = 1;
        for (int j=2*i; j<=MAXN; j+=i)
            prime_divisors[j]++;
    }
}

int solve(int n) {
    int ans = 0;
    for (int i=6; i<=n; i++)
        if (prime_divisors[i] == 2)
            ans++;
    return ans;
}

int main() {
    setup();
    int n;
    cin >> n;
    cout << solve(n) << "\n";
}