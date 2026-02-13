#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int MAX = 5000;
vector<int> primes;
vector<int> lp(MAX+1, 0);
void precompute() {
    for (int i=2; i<=MAX; i++) {
        if (lp[i] == 0) {
            primes.push_back(i);
            lp[i] = i;
        }
        for (int j=i; j<=MAX; j+=lp[i]) {
            lp[j] = lp[i];
        }
    }
}

int main() {
    int t, m;
    cin >> t >> m;


    precompute();
    while (t--) {
        int n;
        cin >> n;
    }
}