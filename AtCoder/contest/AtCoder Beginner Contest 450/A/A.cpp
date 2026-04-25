#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    for (int i=n; i>0; i--) {
        cout << i << "\n,"[i > 1];
    }
}
