#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> &a) {
    int currt = 0;
    for (int ai : a) {
        // find a multiple of ai bigger than currt
        int idx = currt / ai + 1;
        currt = idx * ai;
    }
    return currt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> n;
        vector<int> a(n);
        for (int j=0; j<n; j++)
            cin >> a[j];
        
        cout << solve(a) << "\n";
    }
}