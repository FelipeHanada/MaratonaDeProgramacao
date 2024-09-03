#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int s[n];
    cin >> s[0];
    for (int i=1; i<n; i++) {
        cin >> s[i];
        if (s[i-1]+m < s[i]) {
            // 
        }
    }

    int big = INT32_MIN;
    int prefix[n+1] = {};
    for (int i=0; i<n; i++) {

    }
}