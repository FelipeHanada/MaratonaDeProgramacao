#include <bits/stdc++.h>
using namespace std;

#define _f first
#define _s second
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


/*
5 2 4 | 8 3 9 | 7 1 6
1 4 5   2 8 9   3 6 7
*/

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> ans(3*n);
        for (int i=0; i<3*n; i+=3) ans[i] = i/3 + 1;
        int curr = n + 1;
        for (int i=1; i<3*n; i+=3) {
            ans[i] = curr;
            ans[i+1] = curr + 1;
            curr += 2;
        }
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}
