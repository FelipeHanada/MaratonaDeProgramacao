#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAXN (int)1e8
#define SQN  (int)1e4
#define S    (int)1e4
array<int, MAXN+1> is_prime;

void setup() {
    is_prime[0] = is_prime[1] = -1;

    is_prime[2] = 0;
    for (int i=4; i<=MAXN; i+=2)
        is_prime[i] = -1;

    int c = 1;
    for (int i=3; i<=MAXN; i+=2) {
        if(is_prime[i] == -1) continue;

        is_prime[i] = c++;
        for (ll j= (ll)i * i; j<=MAXN; j+=i)
            is_prime[j] = -1;
    }
}

void solve(int n) {
    if (is_prime[n] == -1) {
        cout << "-1\n";
        return;
    }

    int i = is_prime[n];

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