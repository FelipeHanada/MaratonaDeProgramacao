#include <bits/stdc++.h>
using namespace std;


int solve(int k) {
    // largest number x < k such that x! + (x-1)! is multiple of k
    // x! + (x-1)! = x(x-1)! + (x-1)! = (x-1)!(x+1) is multiple of k
    // x = k - 1 is always a solution and a maxed one since (x-1)!(x+1) = (k-2)!k
    return k-1;
}

int main() {
    int t, k;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> k;
        cout << solve(k) << "\n";
    }
}