#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);

int n, k;
string s;

struct sol {
    vector<int> best, L, R;
};

sol solve(int l, int r) {
    // returns { best overall, best left, best right }
    if (r - l == 0) {
        return { { 0 }, { 0 }, { 0 } };
    }
    if (r - l == 1) {
        if (s[l] == 'o')
            return { { 0, 1 }, { 0, 1 }, { 0, 1 } };
        else
            return { { 0 }, { 0 }, { 0 } };
    }

    int mid = (l + r) / 2;
    sol left = solve(l, mid), right = solve(mid, r);

    sol curr;
    curr.L = left.L;
    for (int i=0; i<right.L.size(); i++) {
        curr.L.push_back(mid - l + right.L[i]);
    }
    curr.R = right.R;
    for (int i=0; i<left.R.size(); i++) {
        curr.R.push_back(r - mid + left.R[i]);
    }

    sol.
}

int main() {
    cin >> n >> k >> s;

}


/*
16 10
xxxoxooooxoxoooo

maximize K / L
K = number of 'o' in the seg.
L = size of the seg.
we can try the best for every candidate of K?



*/