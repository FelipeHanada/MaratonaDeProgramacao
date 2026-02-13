#include <bits/stdc++.h>
using namespace std;


#define ll long long

constexpr int BIG = 2e5;
vector<int> lp(BIG+1, 0);
vector<int> primes;
void lsieve() {
    for (int i=2; i<=BIG; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }

        for (int j=0; i*primes[j]<=BIG; j++) {
            lp[i*primes[j]] = primes[j];
            if (primes[j] == lp[i]) break;
        }
    }
}

void solve() {
    /*
    Occurs that the optimal solution never updates more than one element more than one time
    Argument: Let a solution with cost xbi + ybj with (x>1 and y>1), since we can make both
        ai and aj even by at most bi + bj, then there is a smaller cost solution.


    then we can find the minimal cost for the following:
        1. updates ai any number of times AND do not updates aj
        2. updates ai any number of times AND updates aj a single time

    1.a) ai and aj are even => 0
      b) ai is odd and aj is even => bi
      c) ai and aj are odd =>  
    */

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    multiset<int> pr;
    int evens = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (!(a[i]%2)) evens++;
        for (int j=a[i]; j; j /= lp[j]) {
            pr.insert(lp[j]);
        }
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    ll ans = INT64_MAX;

    // testing case 1
    if (evens >= 2) {
        cout << "0\n";
        return;
    }
    if (evens == 1) {
        for (int i=0; i<n; i++) {
            if (a[i] % 2) {
                ans = min(ans, b[i]);
            }
        }
    }
    for (int i=0; i<n; i++) {
    }

    // testing case 2
}

int main() {
    lsieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}