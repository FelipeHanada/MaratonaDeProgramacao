#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<int> t;
    Fenwick(int n) : n(n), t(n, 0) { }
    void add(int i, int v) {
        for (; i<n; i=i|(i+1)) t[i] += v;
    }
    int get(int r) {
        int ans = 0;
        for (; r>=0; r=(r&(r+1))-1) ans += t[r];
        return ans;
    }
    int get(int l, int r) { return get(r) - get(l - 1); }
};
