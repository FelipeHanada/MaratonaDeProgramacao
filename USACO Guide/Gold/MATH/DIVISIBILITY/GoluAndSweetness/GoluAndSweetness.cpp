//  https://www.codechef.com/problems/COZIE
#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 1e5;
int N, Q;
int prefix[MAX_N + 1];

int main() {
    cin >> N >> Q;

    prefix[0] = 0;
    for (int i=0; i<N; i++) {
        int n; cin >> n;

        prefix[i + 1] = prefix[i];
        if (n == 3 || n == 4 || n == 6)
            prefix[i + 1] += 1;
    }

    for (int i=0; i<Q; i++) {
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l - 1] << endl;
    }
}
