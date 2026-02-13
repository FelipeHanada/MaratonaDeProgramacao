#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<bool> v(n);
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        v[i] = x;
    }

    int mask = 0;
    do {
        vector<bool> v_mask(8);
        for (int i=0; i<8; i++)
            v_mask[i] = mask & (1 << i);

        int applies = 0;
        // tries greedy algo.
        for (int i=-n; i<n; i++) {
            // run from the left to right trying to zero a using current mask
        }
        

        mask++;
    } while (mask < (1 << 8));
}
