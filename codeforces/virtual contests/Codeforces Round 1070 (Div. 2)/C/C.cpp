#include <bits/stdc++.h>
using namespace std;


void precompute() {

}

/*
a ordem da última soma é sempre
    impar - par - par - par - ... - par
    ou nada

a sequencia deve ser então:
    quantidade par de ímpares + pares + (impar - par - par ...)

5
4 1 3 1 2

3 1 1
4 2



*/

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> even, odd;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x % 2) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    sort(even.rbegin(), even.rend());
    sort(odd.begin(), odd.end());

    even.insert(even.begin(), 0);
    for (int i=1; i<even.size(); i++) {
        even[i] += even[i-1];
    }
    
    for (int k=1; k<=n; k++) {
        // desejamos colocar uma quantidade impar de impares e qualquer de pares
        // se não for possível não dá

        if (odd.empty()) {
            cout << "0 ";
        } else {

            if (even.size() >= k) {
                cout << odd.back() + even[k-1] << ' ';
            } else {
                int r = k - even.size() + 1;
                // odds needed
                if (r % 2) {
                    // nice
                    cout << odd.back() + even.back() << ' ';
                } else {
                    // can we remove an even number?
                    if (odd.size() >= r + 1 && even.size() >= 2) {
                        cout << odd.back() + even[even.size()-2] << ' ';
                    } else {
                        cout << "0 ";
                    }
                }
            }

        }
    }
    cout << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}