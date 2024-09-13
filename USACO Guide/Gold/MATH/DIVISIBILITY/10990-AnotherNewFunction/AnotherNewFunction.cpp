//  https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1931
#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 2e6;

int dphi[MAX_N + 1];
int prefix[MAX_N + 1];

void calc() {
    iota(dphi, dphi + MAX_N + 1, 0);

    prefix[0] = prefix[1] = 0;
    dphi[1] = 0;
    for (int i=2; i<=MAX_N; i++) {
        if (dphi[i] == i) {
            for (int j=i; j<=MAX_N; j+=i) {
                dphi[j] -= dphi[j] / i;
            }
        }

        dphi[i] = 1 + dphi[dphi[i]];

        prefix[i] = prefix[i - 1] + dphi[i];
    }
}

int sodf(int m, int n) {
    return prefix[n] - prefix[m - 1];
}

int main() {
    calc();

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int m, n;
        cin >> m >> n;

        cout << sodf(m, n) << endl;
    }
}