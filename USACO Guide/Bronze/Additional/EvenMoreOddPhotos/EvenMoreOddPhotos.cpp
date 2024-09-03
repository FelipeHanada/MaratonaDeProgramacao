#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int odd = 0;   
    int k;
    for (int i=0; i<n; i++) {
        cin >> k;
        if (k % 2) odd++;
    }
}