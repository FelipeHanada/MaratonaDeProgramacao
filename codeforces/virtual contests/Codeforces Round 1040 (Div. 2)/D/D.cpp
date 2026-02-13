#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

void precompute() {

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    // precisamos contar o número de elementos maiores do que a[i] a esquerda e à direita


    vector<int> big_prefix(n, 0); // number of elements a[j] bigger than a[i] with j < i 
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (a[j] > a[i]) {
                big_prefix[i]++;
                ans++;
            }
        }
    }

    for (int i=0; i<n; i++) {
        int delta = -big_prefix[i] + (n-a[i]-big_prefix[i]);
        if (delta < 0) ans += delta;
    }

    cout << ans << '\n';
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