#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=1; i<n; i++) a[i] ^= a[i-1];

    set<int> b;
    b.insert(0);
    for (int i=0; i<n; i++) b.insert(a[i]);
    a.resize(0);
    for (int x : b) a.push_back(x);
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        int l = 0, r = a.size();
        for (int k=30; k >= 0; k--) {
            if ((a[l]&(1<<k)) == (a[r-1]&(1<<k))) continue;

            int ll = l, rr = r-1;
            while (rr - ll > 1) {
                int mid = (ll + rr) / 2;
                if (a[mid]&(1<<k)) rr = mid;
                else ll = mid;
            }

            if (a[i]&(1<<k)) r = rr;
            else l = rr;
        }

        ans = max(ans, a[i] ^ a[l]);
    }

    cout << ans << '\n';
}


/*
Seja um array p tal que:
- p[0] = 0
- p[i] = xi ^ p[i-1]

o problema se torna obter o maior valor de p[i] ^ p[j]

let set the first element p[i] and look for the best p[j]
    1) if we do it naively, we need to check O(n) possible p[j] candidates
    2) alternatively, we can iterate through the bits and while maintaining a range of good candidates

*/