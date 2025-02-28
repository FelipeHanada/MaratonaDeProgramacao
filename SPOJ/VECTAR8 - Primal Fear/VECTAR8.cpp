#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAXN 999999
array<int, MAXN+1> is_prime;
vector<int> vprimes;

bool check(int p) {
    vector<int> digits;

    while (p) {
        int digit = p % 10;
        if (digit == 0) return false;
        digits.push_back(digit);
        p /= 10;
    }

    p = 0;
    int i = 1;
    for (auto d : digits) {
        p += i * d;
        if (!is_prime[p]) return false;
        i *= 10;
    }

    return true;
}

void setup() {
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;

    vprimes.push_back(2);
    for (int i=4; i<=MAXN; i+=2)
        is_prime[i] = false;

    for (int i=3; i<=MAXN; i+=2) {
        if (!is_prime[i]) continue;

        if (check(i))
            vprimes.push_back(i);

        for (ll j=(ll)i*i; j<=MAXN; j+=i)
            is_prime[j] = false;
    }
}

int solve(int n) {
    auto it = upper_bound(vprimes.begin(), vprimes.end(), n);
    return it - vprimes.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    setup();

    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cout << solve(n) << "\n";
    }
}