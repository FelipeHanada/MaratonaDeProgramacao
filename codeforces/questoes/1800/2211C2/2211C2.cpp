#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        bool ok = 1;
        for (int i=0; ok && i<k; i++) {
            bool c = 1; // a is constant
            for (int j=i; j+k<n; j+=k) if (a[j] != a[j+k]) c = 0;

            if (c) {
                // b must also be constant
                int last = -1;
                for (int j=i; j<n; j+=k) if (b[j] != -1) {
                    if (last == -1) last = b[j];
                    else if (last != b[j]) ok = 0;
                }

                if (last != -1) b[i] = last;
            } else {
                // b must be identical to a
                for (int j=i; j<n; j+=k) {
                    if (b[j] != -1 && b[j] != a[j]) ok = 0;
                }

                b[i] = a[i];
            }
        }

        vector<int> cntA(n+1, 0), cntB(n+1, 0);
        for (int i=0; i<k; i++) {
            cntA[a[i]]++;
            if (b[i] != -1) cntB[b[i]]++;
        }

        for (int i=1; i<=n; i++) {
            if (cntB[i] > cntA[i]) ok = 0;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}

/*
consider that we have a solution for an interval [l, r] (of size  >= k)
    can we build a solution for the interval [l, r + 1]?

for a solution of the interval [l, r+1], the subinterval [l, r] must also be a solution
    considering a solution on the interval [l, r]
    the only constraint we need to satisfy is the last k-window of [l, r+1]
    (only the last k-window of [l, r] is important, lets consider l as the first element in this window)

    in this window:
        1. we need to satisfy the new element a[r+1]
        2. we dont need to satisfy a[l] anymore
        3. we lose the element b[l]
        4. we gain the element b[r+1]

    if a[l] = b[l], then a[r+1] = b[r+1]
    if a[l] != b[l], then a[r+1] = a[l] and b[r+1] = b[l]
    then, the equality must be satisfied
        { a[l], b[r+1] } = { a[r+1], b[l] }

    (i) if a[l] = a[r + 1], then b[r + 1] = b[l]
    (ii) if a[l] != a[r+1], then b[r + 1] = a[r + 1]

these properties applies to all subsequences of indices modulo k

for a subsequence:
    if (ii) occurs once, b[i] = a[i] propagates for the whole sequence
    else, (i) must be satisfied, then the b subsequence must be constant

we can check if the subsequence of a is constant
    if so, check if b is constant
    else check if a = b in the subsequence
*/