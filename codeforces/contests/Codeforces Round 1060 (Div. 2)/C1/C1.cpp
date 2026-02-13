#include <bits/stdc++.h>
using namespace std;

#define ll long long


/*
I) 1 par + 1 par -> 0
II) 1 par + 1 ímpar -> 1 (no máximo)
III) 1 ímpar + 1 ímpar -> 2 (no máximo)

II) check for prime decomp. se não tem primo comum -> 1

III) check for solutions with cost 1 existe um a[i]+1 que tem primo comum com outro -> 1
                                                                                c.c. -> 2
*/

vector<int> pr;
vector<int> lp(2e5+1);
void precompute() {
    lp[0] = lp[1] = 0;
    for (int i=2; i<=2e5; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; i*pr[j] <= 2e5; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    int odds = 0, even = 0;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            odds++;
        } else {
            even++;
        }
    }
    int trash;
    for (int i=0; i<n; i++) cin >> trash;

    if (even >= 2) {
        cout << 0 << '\n';
        return;
    }
    
    unordered_set<int> p;
    for (int i=0; i<n; i++) {
        unordered_set<int> curr;
        for (int j=a[i]; lp[j]; j /= lp[j]) {
            if (p.count(lp[j]) && !curr.count(lp[j])) {
                cout << 0 << '\n';
                return;
            }
            p.insert(lp[j]);
            curr.insert(lp[j]);
        }
    }

    if (even == 1) {
        cout << 1 << '\n';
        return;
    }

    for (int i=0; i<n; i++) {
        for (int j=a[i]+1; lp[j]; j /= lp[j]) {
            if (p.count(lp[j])) {
                cout << 1 << '\n';
                return;
            }
        }
    }
    
    cout << 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
