#include <bits/stdc++.h>
using namespace std;
 
 
int phi(int n) {
    int r = n;
 
    for (int i=2; i*i<=n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
        
            r -= r / i;
        }
    }
 
    if (n > 1)
        r -= r/ n;
 
    return r;
}
 
int main() {
    freopen("calc.in", "r", stdin);
    freopen("calc.out", "w", stdout);
 
    int n, k;
    cin >> n >> k;
 
    int phi_k = phi(k);
    int e1 = (n % phi(phi_k));
    int e2 = (1 << e1) % phi_k;
    cout << ((1 << e2) % k + 1) % k << endl;
}
