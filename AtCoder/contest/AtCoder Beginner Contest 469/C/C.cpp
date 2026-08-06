#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


int main() {
    int n; string s;
    cin >> n >> s;

    vector<int> ans(n+1, 0);

    int hits = 0, curr = 0;
    for (int i=0; i<n; i++) {
        if (curr == 0) {
            hits++;
            curr++;
        }
        if (s[i] == 'x') curr--;
        ans[i+1] = hits;
    }

    int i = 0;
    int sum = 0;
    for (int l=1; l<=n; l++) {
        while (i + 1 <= n && ans[i+1] <= l) {
            i++;
            sum++;
        }
        cout << sum << '\n';
    }
}
