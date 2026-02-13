#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            set<int> s;
            for (int k=0; k<i; k++) s.insert(ans[k][j]);
            for (int k=0; k<j; k++) s.insert(ans[i][k]);
            int mex = 0;
            for (auto it = s.begin(); it!=s.end() && *it == mex; it++) {
                mex++;
            }
            ans[i][j] = mex;
            cout << mex << ' ';
        }
        cout << '\n';
    }
}