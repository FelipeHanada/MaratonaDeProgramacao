#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;

    int B = sqrt(n);

    vector<vector<int>> s(B+1, vector<int>(n, 0));
    vector<int> ans(n, 0);

    while (k--) {
        int a, l, d; cin >> a >> l >> d; a--;

        if (d <= B) {
            s[d][a]++;
            if (a+l*d < n) s[d][a+l*d]--;
        } else {
            for (int j=a; j<n && l; j+=d, l--) {
                ans[j]++;
            }
        }
    }

    for (int i=1; i<=B; i++) {
        for (int j=i; j<n; j++) {
            s[i][j] += s[i][j-i];
        }
    }

    for (int i=1; i<=B; i++) {
        for (int j=0; j<n; j++) ans[j] += s[i][j];
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

/*
8 3
3 4 1
2 3 3
3 2 2


*/