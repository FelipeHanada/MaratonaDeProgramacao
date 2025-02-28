#include <bits/stdc++.h>
using namespace std;


#define MAXN 1e8
vector<int> lp(MAXN+1);
vector<int> pr;

void linear_sieve() {
    int c = 0;
    for (int i=2; i<=MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }

        for (int j=0; i * pr[j] <= MAXN; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

void solve(int n) {
    auto it = lower_bound(pr.begin(), pr.end(), n);

    if (*it != n) {
        cout << "-1\n";
        return;
    }

    int i = it - pr.begin();

    int a = floor((-1 + sqrt(1 + 8*i)) / 2);
    int b = i - (a*a + a)/2;

    cout << a+1 << " " << b+1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    linear_sieve();
    
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        solve(n);
    }
}