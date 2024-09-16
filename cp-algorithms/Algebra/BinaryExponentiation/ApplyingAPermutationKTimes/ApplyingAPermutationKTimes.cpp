#include <bits/stdc++.h>
using namespace std;


vector<int> apply_permutation(const vector<int> &sequence, const vector<int> &permutation) {
    vector<int> r(sequence.size());
    
    for (int i=0; i<sequence.size(); i++) {
        r[i] = sequence[permutation[i]];
    }

    return r;
}

void permute_k(vector<int> &sequence, vector<int> permutation, int k) {
    while (k > 0) {
        if (k & 1)
            sequence = apply_permutation(sequence, permutation);
        
        k >>= 1;
        permutation = apply_permutation(permutation, permutation);
    }
}

int main() {
    vector<int> v = { 0, 1, 2, 3, 4 };
    vector<int> perm = { 4, 0, 1, 2, 3 };

    permute_k(v, perm, 2);

    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
