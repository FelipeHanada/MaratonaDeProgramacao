//  https://www.spoj.com/problems/TIP1/
#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_M = 1e7 - 1;
int phi[MAX_M + 1];
set<pair<int, int>> phi_perm; 

bool check_perm(int x, int y) {
    map<int, int> alg = [&]() {
        map<int, int> tmp;
        for (int i=0; i<9; i++) {
            tmp.emplace(make_pair(i, 0));
        }
        return tmp;
    }();

    while (x > 0 && y > 0) {
        alg[x % 10]++;
        alg[y % 10]--;

        x /= 10;
        y /= 10;
    }

    for (auto p : alg) {
        if (p.second != 0) return false;
    }

    return true;
}

void calc_phi() {
    iota(phi, phi + MAX_M + 1, 0);

    for (int i=2; i<=MAX_M; i++) {
        //  calcs phi and checks permutations on i   
    }
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;


    }
}
