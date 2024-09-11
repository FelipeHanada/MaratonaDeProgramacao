#include <bits/stdc++.h>
using namespace std;


vector<int> eulersTotientFunction1ToN(int n) {
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);

    for (int i=2; i<n+1; i++) {
        if (phi[i] == i) {  // i is prime
            for (int j=i; j<n+1; j+=i) {  // for every multiple of i 
                phi[j] -= phi[j] / i;
            }
        }
    }

    return phi;
}

int main() {
    vector<int> phi = eulersTotientFunction1ToN(10);
    for (int i=0; i<phi.size(); i++) {
        cout << "phi(" << i << ") = " << phi[i] << endl;
    }
}
