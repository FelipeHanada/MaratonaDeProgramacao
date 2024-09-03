#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1000;
int succ[MAX_N];
int cycle_start;
set<int> cycle;

int main() {
    int n; cin >> n;

    for (int a=0; a<n; a++) {
        int b; cin >> b; b--;
        succ[a] = b;
    }

    for (int i=0; i<n; i++) {
        set<int> seen;
        int curr = i;
        while (seen.find(curr) == seen.end()) {
            seen.insert(curr);
            curr = succ[curr];
        }

        cout << curr + 1 << " ";
    }
    cout << endl;
}