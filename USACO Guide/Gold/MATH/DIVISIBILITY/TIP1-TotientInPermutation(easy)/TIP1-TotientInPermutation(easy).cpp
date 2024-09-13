//  https://www.spoj.com/problems/TIP1/
#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_M = 1e7 - 1;
constexpr int MAX_PHI_PERM = 2068;
array<pair<int, int>, MAX_PHI_PERM> phi_perm; 
int phi[MAX_M];

bool check_perm(int x, int y) {
    if ((int) log10(x) != (int) log10(y)) return false;
    
    int alg[10] = {};

    for (; x > 0 && y > 0; x /= 10, y /= 10) {
        alg[x % 10]++;
        alg[y % 10]--;
    }

    for (int i=0; i<=9; i++) {
        if (alg[i] > 0) return false;
    }

    return true;
}

void calc_phi() {
    iota(phi, phi + MAX_M + 1, 0);

    int phi_perm_i = 0;
    for (int i=2; i<MAX_M; i++) {
        if (phi[i] == i) {
            for (int j=i; j<MAX_M; j+=i) {
                phi[j] -= phi[j] / i;
            }
        } else if (check_perm(i, phi[i])) {
            phi_perm[phi_perm_i++] = { i, phi[i] };
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    calc_phi();

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        auto last = upper_bound(phi_perm.begin(), phi_perm.end(), make_pair(n, 0));

        pair<int, int> sol = { INT32_MAX, 1 };
        for (auto it = phi_perm.begin(); it != last; it++) {
            if (it->first / (float) it->second <= sol.first / (float) sol.second) {
                sol = *it;
            }
        }

        if (sol.first == INT32_MAX) {
            cout << "No solution" << endl;
        } else {
            cout << sol.first << endl;
        }
    }
}
