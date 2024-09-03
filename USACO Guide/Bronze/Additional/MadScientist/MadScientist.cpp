#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int count = 0;
    int i = 0;
    while (i < n) {
        while (i < n && a[i] == b[i]) i++;
        if (i < n) count++;
        while (i < n && a[i] != b[i]) i++;
    }

    cout << count << endl;
}
