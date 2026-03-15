#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define _1 first
#define _2 second
using ll = long long;

int main() { _
    int n, x;
    cin >>n >> x;
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        if (ai < x) {
            cout << "1\n";
            x = ai;
        } else {
            cout << "0\n";
        }
    }
}
