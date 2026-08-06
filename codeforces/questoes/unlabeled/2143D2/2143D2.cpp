#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

    }
}

/*
the problem is to count the number of subsequences that satisfy:
    there isn't a triple i < j < k s.t. a[i] > a[j] > a[k]

we can count the number of subsequences a.t.
*/
