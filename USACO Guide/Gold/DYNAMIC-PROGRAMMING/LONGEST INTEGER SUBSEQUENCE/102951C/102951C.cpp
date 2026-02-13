#include <bits/stdc++.h>
using namespace std;


// let P1 = a1...an be the first permutation and P2 = b1...bn the second
// the LCS of P1 and P2 is a subsequence of P1 (and P2)
// then we can get a equivalent problem swapping all ai by i
// and replacing the occurrence of ai em P2 with also i
// this problem is equivalent to find the LIS in P2 (swapped)


constexpr int MAX_N = 1e5;
int p1[MAX_N+1];
int p2[MAX_N];

int main() {
    int n;
    cin >> n;

    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        p1[x] = i;
    }

    for (int i=0; i<n; i++) {
        cin >> x;
        p2[i] = p1[x];
    }

    // find LIS in p2
    vector<int> dp;
    dp.push_back(INT32_MIN);
    for (int i=0; i<n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), p2[i]);
        if (it == dp.end()) {
            dp.push_back(p2[i]);
        } else {
            *it = p2[i];
        }
    }

    cout << dp.size() - 1 << '\n';
}
