#include <bits/stdc++.h>
using namespace std;

bool validate(int n, int k) {
    int next = (k - 1) % (2*n);
    if (next < n) return false;
    
    for (int i=1; i<n; i++) {
        int step = k - ((2*n-i+1) - next);
        next = step % (2*n-i);
        if (next < n) return false;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i=n+1; i<1e6; i++) {
        if (validate(n, i)) {
            cout << i << '\n';
            break;
        }
    }
}