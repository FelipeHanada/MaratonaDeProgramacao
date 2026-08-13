#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(0);


int main() {
    vector<vector<int>> prob(3, vector<int>(3, 0));
    for (int i=0; i<3; i++) {
        int x;
        for (int j=0; j<6; j++) {
            cin >> x;
            x -= 4;
            if (x >= 0 && x < 3) prob[i][x]++;
        }
    }


    double ans = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) if (i != j) {
            for (int k=0; k<3; k++) if (i != k && j != k) {
                ans += prob[i][0] * prob[j][1] * prob[k][2] / 6.f / 6.f /6.f;
            }
        }
    }

    cout << setprecision(9) <<  ans << '\n';
}
