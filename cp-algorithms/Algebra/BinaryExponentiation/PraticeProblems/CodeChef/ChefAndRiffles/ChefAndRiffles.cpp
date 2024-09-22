#include <bits/stdc++.h>
using namespace std;


vector<int> apply_perm(const vector<int> &v, const vector<int> &perm) {
    vector<int> r(v.size());

    for (int i=0; i<v.size(); i++)
        r[i] = v[perm[i]];

    return r;
}

vector<int> solve(int n, int k) {
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    vector<int> perm(n);
    for (int i=0; i<n/2; i++) {
        perm[i] = i * 2;
        perm[n/2+i] = i * 2 + 1;
    }

    while (k > 0) {
        if (k & 1)
            v = apply_perm(v, perm);

        perm = apply_perm(perm, perm);
        k >>= 1;
    }

    return v;
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n, k;
        cin >> n >> k;

        for (int x : solve(n, k)) {
            cout << x << " ";
        }
        cout << endl;
    }
}