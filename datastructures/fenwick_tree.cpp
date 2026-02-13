#include <bits/stdc++.h>
using namespace std;



struct FenwickTree {
    vector<int> t;

    FenwickTree(int n) {
        t.assign(n+1, 0);
    }

    int sum(int r) {
        int sum = 0;
        while (r > 0) {
            sum += t[r];
            r -= r & (-r);
        }
        return sum;
    }

    void add(int i, int delta) {
        while (i < t.size()) {
            t[i] += delta;
            i += i & (-i);
        }
    }
};

int main() {
    FenwickTree ft(10);

    for (int i=1; i<=10; i++) {
        ft.add(i, i);
    }

    for (int i=1; i<=10; i++) {
        cout << ft.sum(i) << ' ';
    }
    cout << '\n';
}
