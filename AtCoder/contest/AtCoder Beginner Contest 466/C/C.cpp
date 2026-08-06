#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


bool query(int i, int j) {
    cout << "? " << i << ' ' << j << '\n';
    fflush(stdout);
    string ans; cin >> ans;
    return ans == "Yes";
}

int main() {
    int n; cin >> n;
    int ans = 0;

    int i = 1, j = 2;
    while (i < n) {
        j = max(j, i+1);
        while (j <= n && query(i, j)) j++;
        ans += j - i - 1;
        i++;
    }

    cout << "! " << ans << '\n';
}


/*
we can always assume 0 is on 0


(    )___)
 i       j

1 => 0
2 => 1
3 => 2

*/