#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100000;
int n, m;
int salt[MAX_N];

int main () {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> salt[i];
    }

    for (int i=0; i<n-1; i++) {
        if (salt[i+1] < salt[i] - m)
            salt[i+1] = salt[i] - m;
    }

    for (int i=n; i>0; i--) {
        if (salt[i-1] < salt[i] - m)
            salt[i-1] = salt[i] - m;
    }

    for (int i=0; i<n; i++) {
        cout << salt[i] << ' ';
    }
    cout << '\n';
}