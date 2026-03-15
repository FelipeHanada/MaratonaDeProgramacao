#include <bits/stdc++.h>
using namespace std;


int flog2(int x) {
    return __builtin_clz(1) - __builtin_clz(x);
}

int main() {
    int tt;
    cin >> tt;

    vector<vector<int>> comb(65);
    comb[0].push_back(1);
    comb[1].push_back(1);
    comb[1].push_back(1);
    for (int i=2; i<=64; i++) {
        comb[i].push_back(1);
        for (int j=0; j<comb[i-1].size()-1; j++)
            comb[i].push_back(comb[i-1][j] + comb[i-1][j+1]);
        comb[i].push_back(1);
    }

    while (tt--) {
        int n, k;
        cin >> n >> k;

        int ans = 0;
        if (flog2(n) + 1 > k) ans++;

        for (int maxbit=0; maxbit<flog2(n); maxbit++) {
            for (int sets=max(1, k-maxbit+1); sets<=maxbit+1; sets++) {
                ans += comb[maxbit][sets-1];
            }
        }

        cout << ans << '\n';
    }
}


/*
0001 => 0 + 1 
0010 => 1 + 1 = 2
0011 => 1 + 2 = 3
0100 => 2 + 1 = 4

*/