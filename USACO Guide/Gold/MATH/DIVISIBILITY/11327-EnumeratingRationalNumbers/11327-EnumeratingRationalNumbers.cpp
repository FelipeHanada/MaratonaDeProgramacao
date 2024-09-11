//  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2302
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

constexpr int MAX_D = 200001;
int phi[MAX_D + 1];

void calc_phi() {
    iota(phi, phi + MAX_D + 1, 0);

    for (int i=2; i<=MAX_D; i++) {
        if (phi[i] == i) {
            for (int j=i; j<=MAX_D; j+=i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

//  (0/1)* (1/1) (1/2) (1/3 2/3) (1/4 3/4) (1/5 2/5 3/5 4/5) (1/6 5/6) 1/7,...

int main() {
    calc_phi();
    
    ll k;
    while (cin >> k) {
        if (k == 0) break;

        if (k == 1) {
            cout << "0/1" << endl;
            continue;
        }  //  ignores case 0/1
        k--;

        int d = 1;
        while (k > phi[d]) {
            k -= phi[d];
            d++;
        }

        int n = 1;
        for (; k > 0; n++) {
            if (__gcd(n, d) == 1) {
                k--;
            }
        } n--;

        cout << n << '/' << d << endl;
    }
}
