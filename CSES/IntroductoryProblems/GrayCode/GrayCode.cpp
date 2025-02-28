#include <bits/stdc++.h>
using namespace std;

int graycode(int n, int size) {
    int ans = 0;

    if (n & (1 << (size - 1)))
        ans++;

    for (int i=1; i < size; i++) {
        ans <<= 1;
        if (((n >> (size - i)) & 1) ^ ((n >> (size - (i + 1))) & 1))
            ans++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
        cout << 0;
    cout << "\n";

    int g;
    for (int i=1; g = graycode(i, n); i++) {
        for (int j=n-1; j>=0; j--)
            cout << ((g & (1 << j)) ? 1 : 0);
        cout << "\n";
    }
}