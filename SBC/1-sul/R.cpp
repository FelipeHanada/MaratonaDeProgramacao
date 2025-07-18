#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; double l, q;
    cin >> n >> l >> q;

    vector<string> nomes(n);
    for (int i=0; i<n; i++) cin >> nomes[i];

    int i=-1;
    for (; l > 0; l -= q) {
        i++;
    }

    cout << nomes[i % n] << " " << setprecision(1) << fixed << l + q << '\n';
}
